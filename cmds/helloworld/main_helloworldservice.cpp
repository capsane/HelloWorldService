#define LOG_TAG "main_helloworldservice"

#include <binder/IPCThreadState.h>
#include <binder/ProcessState.h>
#include <binder/IServiceManager.h>
#include <utils/Log.h>

#include <helloworld/HelloWorldService.h>


#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)  


using namespace android;

int main() {
    // 实例化，并注册到系统中
    LOGI("instantiate HelloWorldService:");
    HelloWorldService::instantiate();
    // 创建线程池
    ProcessState::self()->startThreadPool();
    LOGI("HelloWorldService is starting now");
    // 在线程池中等待接收client请求
    IPCThreadState::self()->joinThreadPool();
    return 0;
}