#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <helloworld/HelloWorldService.h>
#include <helloworld/BnHelloWorldService.h>
#include <utils/Log.h>


#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)  


namespace android {

void HelloWorldService::instantiate() {
    // 注册服务到系统中
    defaultServiceManager()->addService(
        String16("android.capsane.IHelloWorldService"), new HelloWorldService());
        // String16("helloworldservice"), new HelloWorldService());

}

int HelloWorldService::helloWorld(const char* str) {
    LOGI("%s\n", str);
    printf("%s\n", str);
    return 1000;
}

// TODO: decide the policy, and return it.
status_t HelloWorldService::check(const char* api) {
    LOGI("check(%s)\n", api);
    printf("check(%s)\n", api);
    /**
     * 
     *
     */
    
    return 0;
}

HelloWorldService::HelloWorldService() {
    LOGI("HelloWorldService is created");
}

HelloWorldService::~HelloWorldService() {
    LOGI("HelloWorldService is destroyed");
}

// -----------------------------------------------------------------------------------
    // 所以由BnHWS实现
    status_t HelloWorldService::onTransact(
        uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags) {
        return BnHelloWorldService::onTransact(code, data, reply, flags);
    }
// ------------------------------------------------------------------------------------

}; // namespace android
