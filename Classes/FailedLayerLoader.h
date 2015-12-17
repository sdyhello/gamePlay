//
//  FailedLayerLoader.h
//  gamePlay
//
//  Created by 涛 吴 on 15/12/17.
//
//

#ifndef FailedLayerLoader_h
#define FailedLayerLoader_h

#include "cocosbuilder/CocosBuilder.h"
#include "FailedLayer.h"

class FailedLayerLoader : public cocosbuilder::LayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(FailedLayerLoader, loader)
private:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(FailedLayer)
};

#endif /* FailedLayerLoader_h */
