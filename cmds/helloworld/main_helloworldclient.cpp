#define LOG_TAG "main_helloworldclient"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>

#include <utils/Log.h>
#include <utils/RefBase.h>

#include <helloworld/IHelloWorldService.h>


#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)  
#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


using namespace android;

int main() {

    LOGI("HelloWorldClient is starting now");

    sp<IServiceManager> sm = defaultServiceManager();
    sp<IBinder> binder;
    sp<IHelloWorldService> mHelloWorldManager;

    do {
        binder = sm->getService(String16("android.capsane.IHelloWorldService"));
        // binder = sm->getService(String16("helloworldservice"));
        if (binder != 0) {
            break;
        }
        LOGI("HelloWorldService is not working, waiting...");
        usleep(60000);
    } while (true);

    mHelloWorldManager = interface_cast<IHelloWorldService>(binder);
    int result = mHelloWorldManager->helloWorld("hello, world");
    int policy = mHelloWorldManager->check("takePicture:camera");

    LOGI("HelloWorldClient:helloWorld() result is %d \n", result);
    LOGI("HelloWorldClient:check() policy is %d \n", policy);

    return 0;
}