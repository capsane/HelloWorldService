#ifndef ANDROID_IHELLO_WORLD_SERVICE_H
#define ANDROID_IHELLO_WORLD_SERVICE_H

#include <binder/IInterface.h>

namespace android {

// 定义HelloWorldService使用的RPC代码，code
enum {
    HW_HELLOWORLD = IBinder::FIRST_CALL_TRANSACTION,
    HW_CHECK,
    HW_SET_FLAG
};

// 定义服务接口类IHelloWorldService 
class IHelloWorldService: public IInterface {

    public:
    // 服务接口宏
    DECLARE_META_INTERFACE(HelloWorldService);
    // 服务函数: 提供给资源访问点API
    virtual int helloWorld(const char* str)=0;
    virtual int check(const char* api)=0;
    // 服务函数: 用于APP更新rules
    virtual int setAccessFlag(const char* resourceType, int accessFlag)=0;
};

}; // namespace android

#endif