#ifndef ANDROID_IHELLO_WORLD_SERVICE_H
#define ANDROID_IHELLO_WORLD_SERVICE_H

#include <binder/IInterface.h>

namespace android {

// 定义HelloWorldService使用的RPC代码，code
enum {
    HW_HELLOWORLD = IBinder::FIRST_CALL_TRANSACTION,
    HW_WIFI_ENABLE,
    HW_BT_ENABLE,
    HW_SENSOR_ACC,
    HW_CHECK
};

// 定义服务接口类IHelloWorldService 
class IHelloWorldService: public IInterface {

    public:
    // 服务接口宏
    DECLARE_META_INTERFACE(HelloWorldService);
    // 服务函数
    virtual int helloWorld(const char* str)=0;
    virtual int check(const char* api)=0;
};

}; // namespace android

#endif