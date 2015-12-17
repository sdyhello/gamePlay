//
//  RankLayerLoader.h
//  gamePlay
//
//  Created by 涛 吴 on 15/12/17.
//
//

#ifndef RankLayerLoader_h
#define RankLayerLoader_h

#include "cocosbuilder/CocosBuilder.h"
#include "RankLayer.h"

class RankLayerLoader : public cocosbuilder::LayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(RankLayerLoader, loader)
private:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(RankLayer)
};

#endif /* RankLayerLoader_h */
