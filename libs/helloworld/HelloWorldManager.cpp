#define LOG_TAG "HelloWorldManager"

#include <stdint.h>
#include <sys/types.h>

#include <utils/Errors.h>
#include <utils/RefBase.h>
#include <utils/Singleton.h>

#include <binder/IBinder.h>
#include <binder/IServiceManager.h>

#include <helloworld/HelloWorldManager.h>


// ----------------------------------------------------------------------------
namespace android {
// ----------------------------------------------------------------------------

// 单例模式？不对
ANDROID_SINGLETON_STATIC_INSTANCE(HelloWorldManager)

HelloWorldManager::HelloWorldManager()
{
    LOGI("HelloWorldManager created...");
}

HelloWorldManager::~HelloWorldManager()
{
    LOGI("HelloWorldManager destroyed...");
}

void HelloWorldManager::helloWorldServiceDied()
{
  mHelloWorldServer.clear();
}

// 
status_t HelloWorldManager::assertState() const {
    if (mHelloWorldServer == NULL) {
        // try for one second
        const String16 name("android.capsane.IHelloWorldService");
        for (int i=0 ; i<4 ; i++) {
            status_t err = getService(name, &mHelloWorldServer);
            if (err == NAME_NOT_FOUND) {
                LOGI("helloworldservice name not found!");
                usleep(60000);
                continue;
            }
            if (err != NO_ERROR) {
                return err;
            }
            break;
        }

        class DeathObserver : public IBinder::DeathRecipient {
            HelloWorldManager& mHelloWorldManager;
            virtual void binderDied(const wp<IBinder>& who) {
                ALOGW("helloworldservice died [%p]", who.unsafe_get());
                mHelloWorldManager.helloWorldServiceDied();
            }
        public:
            DeathObserver(HelloWorldManager& mgr) : mHelloWorldManager(mgr) { }
        };
        mDeathObserver = new DeathObserver(*const_cast<HelloWorldManager *>(this));
        mHelloWorldServer->asBinder()->linkToDeath(mDeathObserver);
    }
    return NO_ERROR;
}


int HelloWorldManager::helloWorld(const char *str)
{   
    if (assertState() == NO_ERROR) {
        int result = mHelloWorldServer->helloWorld("hello, world");
        return result;
    }
    return -1;
}

int HelloWorldManager::check(const char *resourceType)
{   
    if (assertState() == NO_ERROR) {
        int accessFlag = mHelloWorldServer->check(resourceType);
        return accessFlag;
    }
    return -1;
}

int HelloWorldManager::setAccessFlag(const char *resourceType, int accessFlag) 
{
    if (assertState() == NO_ERROR) {
        int result = mHelloWorldServer->setAccessFlag(resourceType, accessFlag);
        return result;
    }
    return -1;

}

// ----------------------------------------------------------------------------
}; // namespace android

