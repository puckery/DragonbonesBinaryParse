change 20150326

解析相关代码已移植到
https://github.com/DragonBones/DragonBonesCPP/tree/optimization


dragonbones的二进制解析代码，经不严谨测试，大概提升30%的解析效率。

1. 下载最新版本的dragonbones cpp
https://github.com/DragonBones/DragonBonesCPP

2. 覆盖dragonbones目录，在项目中增加文件链接并编译

3. 下载xml2fb工具将相应的xml转换为二进制形式(https://github.com/puckery/xml2fb)
XMLToFB -s x:\skeleton.xml
XMLToFB -t x:\texture.xml

4. 包含 "DBCCFactoryExt.h" 并用DBCCFactoryExt::getInstance()...进行测试
