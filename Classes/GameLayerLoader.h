//
//  GameLayerLoader.h
//  gamePlay
//
//  Created by 涛 吴 on 15/12/16.
//
//

#ifndef GameLayerLoader_h
#define GameLayerLoader_h

#include "cocosbuilder/CocosBuilder.h"
#include "GameLayer.h"

class GameLayerLoader : public cocosbuilder::LayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(GameLayerLoader, loader)
private:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(GameLayer)
};

#endif /* GameLayerLoader_h */
