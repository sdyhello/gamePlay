//
//  OPTestLayerLoader.h
//  gamePlay
//
//  Created by 涛 吴 on 15/12/8.
//
//

#ifndef OPTestLayerLoader_h
#define OPTestLayerLoader_h
#include "cocosbuilder/CocosBuilder.h"
#include "OPTestLayer.h"

class OPTestLayerLoader : public cocosbuilder::LayerLoader {
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(OPTestLayerLoader, loader);
    
protected:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(OPTestLayer);
};

#endif /* OPTestLayerLoader_h */
