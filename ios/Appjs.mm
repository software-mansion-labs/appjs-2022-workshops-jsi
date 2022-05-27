#import "Appjs.h"
#import <React/RCTBridge+Private.h>
#import "react-native-appjs.h"

using namespace facebook;

@implementation Appjs

RCT_EXPORT_MODULE()

RCT_EXPORT_BLOCKING_SYNCHRONOUS_METHOD(install)
{
    RCTBridge* bridge = [RCTBridge currentBridge];
    RCTCxxBridge* cxxBridge = (RCTCxxBridge *)bridge;
    jsi::Runtime &runtime = *reinterpret_cast<jsi::Runtime *>(cxxBridge.runtime);
    install(runtime);
    return @true;
}

@end
