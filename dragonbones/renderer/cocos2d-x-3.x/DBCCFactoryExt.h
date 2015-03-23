#ifndef DBCC_FACTORY_EXT_H
#define DBCC_FACTORY_EXT_H

#include "DragonBonesHeaders.h"
#include "DBCCRenderHeaders.h"
#include "cocos2d.h"

NAME_SPACE_DRAGON_BONES_BEGIN
class DBCCFactoryExt : public DBCCFactory
{
private:
    static DBCCFactoryExt *_instance;
    
public:

    static DBCCFactoryExt* getInstance();
    static void destroyInstance();
    
    DBCCFactoryExt();
    virtual ~DBCCFactoryExt();

    virtual DragonBonesData* loadDragonBonesData(const std::string &dragonBonesFile, const std::string &name = "");
    virtual ITextureAtlas* loadTextureAtlas(const std::string &textureAtlasFile, const std::string &name = "");

private:
    DRAGON_BONES_DISALLOW_COPY_AND_ASSIGN(DBCCFactoryExt);
};
NAME_SPACE_DRAGON_BONES_END

#endif  // DBCC_FACTORY_EXT_H