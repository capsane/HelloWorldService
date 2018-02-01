#ifndef ANDROID_BP_HELLO_WORLD_SERVICE_H
#define ANDROID_BP_HELLO_WORLD_SERVICE_H

#include <binder/Parcel.h>
#include <helloworld/IHelloWorldService.h>

namespace android {

class BpHelloWorldService: public BpInterface<IHelloWorldService> {
public:
    BpHelloWorldService (const sp<IBinder>& impl);
    // 为什么哪里都要声明这个功能函数
    virtual int helloWorld(const char *str);
    virtual int check(const char *api);
    virtual int setAccessFlag(const char *resourceType, int accessFlag);
};

}; // namaspace android

#endif