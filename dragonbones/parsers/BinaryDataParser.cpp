#include "BinaryDataParser.h"
#include "ConstValues.h"
#include "cocos2d.h"

NAME_SPACE_DRAGON_BONES_BEGIN

BinaryDataParser::BinaryDataParser()
   :_textureScale(1.f),
	_armatureScale(1.f),
	_frameRate(30)
{ }

BinaryDataParser::~BinaryDataParser() {}

float BinaryDataParser::getNumber( const std::string& data, float defaultValue, float nanValue )
{
	if ("" != data)
	{
		const char *value = data.c_str();
		if (
			strcmp(value, "NaN") == 0 ||
			strcmp(value, "") == 0 ||
			strcmp(value, "false") == 0 ||
			strcmp(value, "null") == 0 ||
			strcmp(value, "undefined") == 0
			)
		{
			return nanValue;
		}
		else
		{
			float value = 0.f;
			if (sscanf(data.c_str(), "%f", &value) == 1)
			{
				return value;
			}
		}
	}
	return defaultValue;
}

bool BinaryDataParser::getBool( int intValue, bool defaultValue )
{
	if (0 == intValue)
		return false;
	else
		return true;
}

TextureAtlasData* BinaryDataParser::parseTextureAtlasData( const void *rawTextureAtlasData, float scale /*= 1.f*/ ) const
{
	auto textureFB = fb::GetTextureAtlas(rawTextureAtlasData);

	_textureScale = scale;
	TextureAtlasData *textureAtlasData = new TextureAtlasData();
	const char *name = textureFB->name()->c_str();
	textureAtlasData->name = name ? name : "";
	textureAtlasData->imagePath = textureFB->imagePath()->c_str();

	auto subTextureVector = textureFB->subTextures();
	for (uint32_t i = 0; i < subTextureVector->size(); i++)
	{
		auto subTextureTable = subTextureVector->Get(i);
		TextureData *textureData = parseTextureData(subTextureTable);
		textureAtlasData->textureDataList.push_back(textureData);
	}

	return textureAtlasData;
}

TextureData* BinaryDataParser::parseTextureData( const fb::SubTexture *textureTable ) const
{
	TextureData *textureData = new TextureData();
	textureData->name = textureTable->name()->c_str();
	textureData->rotated = getBool(textureTable->rotated(), false);
	textureData->region.x = textureTable->x() / _textureScale;
	textureData->region.y = textureTable->y() / _textureScale;
	textureData->region.width = textureTable->width() / _textureScale;
	textureData->region.height = textureTable->height() / _textureScale;
	const float frameWidth = textureTable->frameWidth() / _textureScale;
	const float frameHeight = textureTable->frameHeight() / _textureScale;

	if (frameWidth > 0 && frameHeight > 0)
	{
		textureData->frame = new Rectangle();
		textureData->frame->x = textureTable->frameX() / _textureScale;
		textureData->frame->y = textureTable->frameY() / _textureScale;
		textureData->frame->width = frameWidth;
		textureData->frame->height = frameHeight;
	}

	return textureData;
}

DragonBonesData* BinaryDataParser::parseDragonBonesData( const void *rawDragonBonesData, float scale /*= 1.f*/ ) const
{
	_armatureScale = scale;

	auto dragonBonesFB  = fb::GetDragonbones(rawDragonBonesData);
	std::string version = dragonBonesFB->version()->c_str();
	_frameRate = dragonBonesFB->frameRate();

	auto dragonBonesData = new DragonBonesData();
	dragonBonesData->name = dragonBonesFB->name()->c_str();

	// create armatureList
	auto armatureVector = dragonBonesFB->armature();
	for (uint32_t i = 0; i < armatureVector->size(); i++)
	{
		auto armatureTable = armatureVector->Get(i);
		ArmatureData *armatureData = parseArmatureData(armatureTable);
		dragonBonesData->armatureDataList.push_back(armatureData);
	}

	return dragonBonesData;
}

ArmatureData* BinaryDataParser::parseArmatureData( const fb::Armature *armatureTable ) const
{
	ArmatureData *armatureData = new ArmatureData();
	armatureData->name = armatureTable->name()->c_str();

	// create bone list
	auto boneVector = armatureTable->bone();
	for (uint32_t i = 0; i < boneVector->size(); i++)
	{
		auto boneTable = boneVector->Get(i);
		BoneData *boneData = parseBoneData(boneTable);
		armatureData->boneDataList.push_back(boneData);
	}

	// create skin list
	auto skinVector = armatureTable->skin();
	for (uint32_t i = 0; i < skinVector->size(); i++)
	{
		auto skinTable = skinVector->Get(i);
		SkinData *skinData = parseSkinData(skinTable);
		armatureData->skinDataList.push_back(skinData);
	}

	transformArmatureData(armatureData);
	armatureData->sortBoneDataList();

	// create animation list
	auto animationVector = armatureTable->animation();
	for (uint32_t i = 0; i < animationVector->size(); i++)
	{
		auto animationTable = animationVector->Get(i);
		AnimationData *animationData = parseAnimationData(animationTable, armatureData);
		armatureData->animationDataList.push_back(animationData);
	}

	// 没有下述两个结构说明
	//for (const XMLElement *rectangleXML = armatureXML->FirstChildElement(ConstValues::RECTANGLE.c_str()); rectangleXML; rectangleXML = rectangleXML->NextSiblingElement(ConstValues::RECTANGLE.c_str()))
	//{
	//	RectangleData *rectangleData = parseRectangleData(rectangleXML);
	//	armatureData->areaDataList.push_back(rectangleData);
	//}
	//for (const XMLElement *ellipseXML = armatureXML->FirstChildElement(ConstValues::ELLIPSE.c_str()); ellipseXML; ellipseXML = ellipseXML->NextSiblingElement(ConstValues::ELLIPSE.c_str()))
	//{
	//	EllipseData *ellipseData = parseEllipseData(ellipseXML);
	//	armatureData->areaDataList.push_back(ellipseData);
	//}

	return armatureData;
}

BoneData* BinaryDataParser::parseBoneData( const fb::Bone *boneTable ) const
{
	BoneData *boneData = new BoneData();
	boneData->name = boneTable->name()->c_str();

	if (boneTable->parent())
	{
		boneData->parent = boneTable->parent()->c_str();
	}
	boneData->length = boneTable->length();

	// 没有这个结构说明，用默认值
	boneData->inheritRotation = true;
	boneData->inheritScale = false;

	auto transformStruct = boneTable->transform();
	if (transformStruct)
	{
		parseTransform(*transformStruct, boneData->global);
	}
	boneData->transform = boneData->global;

	// 没有下述两个结构说明
	//for (const XMLElement *rectangleXML = boneXML->FirstChildElement(ConstValues::RECTANGLE.c_str()); rectangleXML; rectangleXML = rectangleXML->NextSiblingElement(ConstValues::RECTANGLE.c_str()))
	//{
	//	RectangleData *rectangleData = parseRectangleData(rectangleXML);
	//	boneData->areaDataList.push_back(rectangleData);
	//}
	//for (const XMLElement *ellipseXML = boneXML->FirstChildElement(ConstValues::ELLIPSE.c_str()); ellipseXML; ellipseXML = ellipseXML->NextSiblingElement(ConstValues::ELLIPSE.c_str()))
	//{
	//	EllipseData *ellipseData = parseEllipseData(ellipseXML);
	//	boneData->areaDataList.push_back(ellipseData);
	//}

	return boneData;
}

SkinData* BinaryDataParser::parseSkinData( const fb::Skin *skinTable ) const
{
	SkinData *skinData = new SkinData();
	skinData->name = skinTable->name()->c_str();

	auto slotVector = skinTable->slot();
	for (uint32_t i = 0; i < slotVector->size(); i++)
	{
		auto slotTable = slotVector->Get(i);
		SlotData *slotData = parseSlotData(slotTable);
		skinData->slotDataList.push_back(slotData);
	}

	return skinData;
}

SlotData* BinaryDataParser::parseSlotData( const fb::Slot *slotTable ) const
{
	SlotData *slotData = new SlotData();
	slotData->name = slotTable->name()->c_str();
	slotData->parent = slotTable->parent()->c_str();
	slotData->zOrder = slotTable->z();

	if (slotTable->blendMode())
	{
		slotData->blendMode = getBlendModeByString(slotTable->blendMode()->c_str());
	}

	auto displayVector = slotTable->display();
	for (uint32_t i = 0;i < displayVector->size(); i++)
	{
		auto displayTable = displayVector->Get(i);
		DisplayData *displayData = parseDisplayData(displayTable);
		slotData->displayDataList.push_back(displayData);
	}

	return slotData;
}

DisplayData* BinaryDataParser::parseDisplayData( const fb::Display *displayTable ) const
{
	DisplayData *displayData = new DisplayData();
	displayData->name = displayTable->name()->c_str();
	displayData->type = getDisplayTypeByString(displayTable->type()->c_str());

	//const XMLElement *scalingGridXML = displayXML->FirstChildElement(ConstValues::SCALING_GRID.c_str());
	//if (scalingGridXML)
	//{
	//	displayData->scalingGrid = true;
	//	displayData->scalingGridLeft = scalingGridXML->IntAttribute(ConstValues::A_LEFT.c_str());
	//	displayData->scalingGridRight = scalingGridXML->IntAttribute(ConstValues::A_RIGHT.c_str());
	//	displayData->scalingGridTop = scalingGridXML->IntAttribute(ConstValues::A_TOP.c_str());
	//	displayData->scalingGridBottom = scalingGridXML->IntAttribute(ConstValues::A_BOTTOM.c_str());
	//}
	//else
	//{
	//	displayData->scalingGrid = false;
	//}

	// 格式未说明，用默认
	displayData->scalingGrid = false;

	auto transformStruct = displayTable->transform();
	if (transformStruct)
	{
		parseTransform(*transformStruct, displayData->transform);
		parsePivot(*transformStruct, displayData->pivot);
	}

	// 格式未说明
	//const XMLElement *textXML = displayXML->FirstChildElement(ConstValues::TEXT.c_str());
	//if (textXML)
	//{
	//	displayData->textData = new TextData();
	//	parseTextData(*textXML, *displayData->textData);
	//}

	return displayData;
}

AnimationData* BinaryDataParser::parseAnimationData( const fb::Animation *animationTable, const ArmatureData *armatureData ) const
{
	AnimationData *animationData = new AnimationData();
	animationData->name = animationTable->name()->c_str();
	animationData->frameRate = _frameRate;
	animationData->duration = (int)(round(animationTable->duration() * 1000.f / _frameRate));
	animationData->playTimes = animationTable->loop();
	animationData->fadeTime = animationTable->fadeInTime();
	// 从二进制限定，无需getNumber
	animationData->scale = animationTable->scale();

	// use frame tweenEase, NaN
	// overwrite frame tweenEase, [-1, 0):ease in, 0:line easing, (0, 1]:ease out, (1, 2]:ease in out
	animationData->tweenEasing = getNumber(animationTable->tweenEasing()->c_str(), USE_FRAME_TWEEN_EASING, USE_FRAME_TWEEN_EASING);
	animationData->autoTween = getBool(animationTable->autoTween(), true);

	auto frameVector = animationTable->frame();
	for (uint32_t i = 0; i < frameVector->size(); i++)
	{
		auto frameTable = frameVector->Get(i);
		Frame *frame = parseMainFrame(frameTable);
		animationData->frameList.push_back(frame);
	}

	parseTimeline(*animationData);

	auto timelineVector = animationTable->timeline();
	for (uint32_t i = 0; i < timelineVector->size(); i++)
	{
		auto timelineTable = timelineVector->Get(i);
		TransformTimeline *timeline = parseTransformTimeline(timelineTable, animationData->duration);
		animationData->timelineList.push_back(timeline);
	}

	addHideTimeline(animationData, armatureData);
	transformAnimationData(animationData, armatureData);
	return animationData;
}

TransformTimeline* BinaryDataParser::parseTransformTimeline( const fb::Timeline *timelineTable, int duration ) const
{
	TransformTimeline *timeline = new TransformTimeline();
	timeline->name = timelineTable->name()->c_str();
	timeline->scale = timelineTable->scale();
	timeline->offset = timelineTable->offset();
	timeline->duration = duration;

	auto frameVector = timelineTable->frame();
	for (uint32_t i = 0; i < frameVector->size(); i++)
	{
		auto frameTable = frameVector->Get(i);
		TransformFrame *frame = parseTransformFrame(frameTable);
		timeline->frameList.push_back(frame);
	}

	parseTimeline(*timeline);
	return timeline;
}

Frame* BinaryDataParser::parseMainFrame( const fb::Frame *frameTable ) const
{
	Frame *frame = new Frame();
	parseFrame(*frameTable, *frame);
	return frame;
}

void BinaryDataParser::parseFrame( const fb::Frame &frameTable, Frame &frame ) const
{
	frame.duration = (int)(round(frameTable.duration() * 1000.f / _frameRate));

	if (frameTable.action())
	{
		frame.action = frameTable.action()->c_str();
	}

	if (frameTable.event())
	{
		frame.event = frameTable.event()->c_str();
	}

	if (frameTable.sound())
	{
		frame.sound = frameTable.sound()->c_str();
	}
}

TransformFrame* BinaryDataParser::parseTransformFrame( const fb::Timeline_Frame *frameTable ) const
{
	TransformFrame *frame = new TransformFrame();
	
	frame->duration = (int)(round(frameTable->duration() * 1000.f / _frameRate));
	if (frameTable->action())
	{
		frame->action = frameTable->action()->c_str();
	}
	if (frameTable->event())
	{
		frame->event = frameTable->event()->c_str();
	}
	if (frameTable->sound())
	{
		frame->sound = frameTable->sound()->c_str();
	}
	frame->visible = !getBool(frameTable->hide(), false);

	// NaN:no tween, 10:auto tween, [-1, 0):ease in, 0:line easing, (0, 1]:ease out, (1, 2]:ease in out
	frame->tweenEasing = getNumber(frameTable->tweenEasing()->c_str(), AUTO_TWEEN_EASING, NO_TWEEN_EASING);
	frame->tweenRotate = frameTable->tweenRotate();
	
	// 未声明，用默认
	frame->tweenScale = true;
	frame->displayIndex = frameTable->displayIndex();
	frame->zOrder = frameTable->z();

	auto transform = frameTable->transform();
	if (transform)
	{
		parseTransform(*transform, frame->global);
		parsePivot(*transform, frame->pivot);
	}

	// copy
	frame->transform = frame->global;
	frame->scaleOffset.x = 0.f;
	frame->scaleOffset.y = 0.f;

	auto colorTransform = frameTable->colorTransform();
	if (colorTransform)
	{
		frame->color = new ColorTransform();
		parseColorTransform(*colorTransform, *frame->color);
	}

	return frame;
}

void BinaryDataParser::parseTransform( const fb::Transform &transformTable, Transform &transform ) const
{
	transform.x = transformTable.x() / _armatureScale;
	transform.y = transformTable.y() / _armatureScale;
	transform.skewX = transformTable.skX() * ANGLE_TO_RADIAN;
	transform.skewY = transformTable.skY() * ANGLE_TO_RADIAN;
	transform.scaleX = transformTable.scX();
	transform.scaleY = transformTable.scY();
}

void BinaryDataParser::parsePivot( const fb::Transform &transformTable, Point &pivot ) const
{
	pivot.x = transformTable.pX() / _armatureScale;
	pivot.y = transformTable.pY() / _armatureScale;
}

void BinaryDataParser::parseColorTransform( const fb::ColorTransform &colorTransformTable, ColorTransform &colorTransform ) const
{
	colorTransform.alphaOffset = colorTransformTable.aO();
	colorTransform.redOffset = colorTransformTable.rO();
	colorTransform.greenOffset = colorTransformTable.gO();
	colorTransform.blueOffset = colorTransformTable.bO();
	colorTransform.alphaMultiplier = colorTransformTable.aM() * 0.01f;
	colorTransform.redMultiplier = colorTransformTable.rM() * 0.01f;
	colorTransform.greenMultiplier = colorTransformTable.gM() * 0.01f;
	colorTransform.blueMultiplier = colorTransformTable.bM() * 0.01f;
}

void BinaryDataParser::parseTimeline( Timeline &timeline ) const
{
	int position = 0;
	Frame *frame = nullptr;

	for (size_t i = 0, l = timeline.frameList.size(); i < l; ++i)
	{
		frame = timeline.frameList[i];
		frame->position = position;
		position += frame->duration;
	}

	if (frame)
	{
		frame->duration = timeline.duration - frame->position;
	}
}

NAME_SPACE_DRAGON_BONES_END
