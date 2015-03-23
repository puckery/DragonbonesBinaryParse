#include "DBCCFactoryExt.h"

#include "parsers/BinaryDataParser.h"

NAME_SPACE_DRAGON_BONES_BEGIN
DBCCFactoryExt* DBCCFactoryExt::_instance = nullptr;

DBCCFactoryExt* DBCCFactoryExt::getInstance()
{
    if (!_instance)
    {
        _instance = new DBCCFactoryExt();
    }
    return _instance;
}

void DBCCFactoryExt::destroyInstance()
{
    if (_instance)
    {
       CC_SAFE_DELETE(_instance);
    }
}

DBCCFactoryExt::DBCCFactoryExt() {}
DBCCFactoryExt::~DBCCFactoryExt() {}

DragonBonesData* DBCCFactoryExt::loadDragonBonesData(const std::string &dragonBonesFilePath, const std::string &name)
{
    DragonBonesData *existDragonBonesData = getDragonBonesData(name);

    if (existDragonBonesData)
    {
        return existDragonBonesData;
    }

    const auto &data = cocos2d::FileUtils::getInstance()->getDataFromFile(dragonBonesFilePath);
    if (data.getSize() == 0)
    {
        return nullptr;
    }

    // armature scale
    float scale = cocos2d::Director::getInstance()->getContentScaleFactor();

	dragonBones::BinaryDataParser parser;
	DragonBonesData *dragonBonesData = parser.parseDragonBonesData(data.getBytes(), scale);
    addDragonBonesData(dragonBonesData, name);
    return dragonBonesData;
}

ITextureAtlas* DBCCFactoryExt::loadTextureAtlas(const std::string &textureAtlasFile, const std::string &name)
{
    ITextureAtlas *existTextureAtlas = getTextureAtlas(name);

    if (existTextureAtlas)
    {
        refreshTextureAtlasTexture(name.empty() ? existTextureAtlas->textureAtlasData->name : name);
        return existTextureAtlas;
    }

    const auto &data = cocos2d::FileUtils::getInstance()->getDataFromFile(textureAtlasFile);
    if (data.getSize() == 0)
    {
        return nullptr;
    }

    // textureAtlas scale
    float scale = cocos2d::Director::getInstance()->getContentScaleFactor();

	DBCCTextureAtlas *textureAtlas = new DBCCTextureAtlas();
	dragonBones::BinaryDataParser parser;
	textureAtlas->textureAtlasData = parser.parseTextureAtlasData(data.getBytes(), scale);

    int pos = textureAtlasFile.find_last_of("/");

    if (std::string::npos != pos)
    {
        std::string base_path = textureAtlasFile.substr(0, pos + 1);
        textureAtlas->textureAtlasData->imagePath = base_path + textureAtlas->textureAtlasData->imagePath;
    }

    //
    addTextureAtlas(textureAtlas, name);
    refreshTextureAtlasTexture(name.empty() ? textureAtlas->textureAtlasData->name : name);
    return textureAtlas;
}

NAME_SPACE_DRAGON_BONES_END
