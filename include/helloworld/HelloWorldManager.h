#ifndef HELLO_WORLD_MANAGER_H
#define HELLO_WORLD_MANAGER_H

#include <stdint.h>
#include <sys/types.h>
#include <binder/IBinder.h>
#include <utils/RefBase.h>
#include <utils/Singleton.h>
#include <utils/threads.h>


#include <helloworld/IHelloWorldService.h>


#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)  
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)

namespace android {
// ---------------------------------------------------------------------------

class HelloWorldManager : public Singleton<HelloWorldManager>
{
public:
    HelloWorldManager();
    ~HelloWorldManager();

    int helloWorld(const char* str);
    int check(const char *resourceType);
    int setAccessFlag(const char *resourceType, int accessFlag);

private:
    // DeathRecipient interface
    void helloWorldServiceDied();
    status_t assertState() const;

    mutable sp<IHelloWorldService> mHelloWorldServer;
    mutable sp<IBinder::DeathRecipient> mDeathObserver;
};

}; // namespace android

#endif
