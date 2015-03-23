dragonbones的二进制解析代码

1. 下载最新版本的dragonbones cpp
https://github.com/DragonBones/DragonBonesCPP

2. 覆盖dragonbones目录，在项目中增加文件链接并编译

3. 下载xml2fb工具将相应的xml转换为二进制形式(https://github.com/puckery/xml2fb)
XMLToFB -s x:\skeleton.xml
XMLToFB -t x:\texture.xml

4. #include "DBCCFactoryExt.h"
DBCCFactoryExt::getInstance()->loadDragonBonesData("armatures/DragonBoy/skeleton.bin", "DragonBoy");
DBCCFactoryExt::getInstance()->loadTextureAtlas("armatures/DragonBoy/texture.bin", "DragonBoy");
