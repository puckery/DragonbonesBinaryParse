#ifndef BINARY_DATA_PARSER_H
#define BINARY_DATA_PARSER_H

#include "../DragonBones.h"
#include "BaseDataParser.h"

#include "flatbuffers/flatbuffers.h"
namespace fb = flatbuffers;

#include "dragonbones_generated.h"
#include "dragonbones_texture_generated.h"

NAME_SPACE_DRAGON_BONES_BEGIN
class BinaryDataParser : public BaseDataParser
{
public:
	BinaryDataParser();
	virtual ~BinaryDataParser();

	virtual TextureAtlasData* parseTextureAtlasData(const void *rawTextureAtlasData, float scale = 1.f) const;
	virtual DragonBonesData* parseDragonBonesData(const void *rawDragonBonesData, float scale = 1.f) const;
	//virtual DragonBonesData* getDragonBonesData(const char* data, float scale = 1.f);

private:
	//static bool getBoolean(const xml_node<> &data, const char *key, bool defaultValue);
	static float getNumber(const std::string& data, float defaultValue, float nanValue);
	static bool getBool(int intValue, bool defaultValue);
private:
	TextureData* parseTextureData(const fb::SubTexture *textureTable) const;

	ArmatureData* parseArmatureData(const fb::Armature *armatureTable) const;

	BoneData* parseBoneData(const fb::Bone *boneTable) const;
	SkinData* parseSkinData(const fb::Skin *skinTable) const;
	SlotData* parseSlotData(const fb::Slot *slotTable) const;
	DisplayData* parseDisplayData(const fb::Display *displayTable) const;
	AnimationData* parseAnimationData(const fb::Animation *animationTable, const ArmatureData *armatureData) const;
	TransformTimeline* parseTransformTimeline(const fb::Timeline *timelineTable, int duration) const;
	Frame* parseMainFrame(const fb::Frame *frameTable) const;
	TransformFrame* parseTransformFrame(const fb::Timeline_Frame *frameTable) const;
	//RectangleData* parseRectangleData(const xml_node<> *rectangleXML) const;
	//EllipseData* parseEllipseData(const xml_node<> *ellipseXML) const;

	void parseTimeline(Timeline &timeline) const;
	void parseFrame(const fb::Frame &frameTable, Frame &frame) const;
	void parseTransform(const fb::Transform &transformTable, Transform &transform) const;
	void parsePivot(const fb::Transform &transformTable, Point &pivot) const;
	void parseColorTransform(const fb::ColorTransform &colorTransformTable, ColorTransform &colorTransform) const;
	//void parseTextData(const xml_node<> &textXML, TextData &textData) const;

private:
	mutable float _textureScale;
	mutable float _armatureScale;
	mutable int _frameRate;

private:
	DRAGON_BONES_DISALLOW_COPY_AND_ASSIGN(BinaryDataParser);
};
NAME_SPACE_DRAGON_BONES_END
#endif // BINARY_DATA_PARSER_H
