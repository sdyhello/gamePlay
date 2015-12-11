//
//  WelcomeLayerLoader.h
//  gamePlay
//
//  Created by 涛 吴 on 15/12/11.
//
//

#ifndef WelcomeLayerLoader_h
#define WelcomeLayerLoader_h

#include "cocosbuilder/CocosBuilder.h"
#include "WelcomeLayer.h"

class WelcomeLayerLoader : public cocosbuilder::CCLayerLoader
{
public:
    CCB_STATIC_NEW_AUTORELEASE_OBJECT_METHOD(WelcomeLayerLoader, loader)
private:
    CCB_VIRTUAL_NEW_AUTORELEASE_CREATECCNODE_METHOD(WelcomeLayer)
};
#endif /* WelcomeLayerLoader_h */
