#include <binder/Parcel.h>
#include <helloworld/BpHelloWorldService.h>
#include <utils/Log.h>


#define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)


namespace android {

// helloworld()
int BpHelloWorldService::helloWorld(const char *str) {
    Parcel data, reply;
    // 将服务接口名称保存到发送数据中
    data.writeInterfaceToken(IHelloWorldService::getInterfaceDescriptor());
    // 讲输出字符串保存到发送数据中
    data.writeCString(str);
    // 调用BpBinder类的onTransact()方法
    status_t status = remote()->transact(HW_HELLOWORLD, data, &reply);
    if (status != NO_ERROR) {
        ALOGE("Error %s", strerror(-status));        
        LOGE("Error %s", strerror(-status));
        return -1000;
    } else {
        // 读取helloWorld()方法的调用结果
        int result = reply.readInt32();
        return result;
    }
}

int BpHelloWorldService::check(const char *api) {
    Parcel data, reply;
    data.writeInterfaceToken(IHelloWorldService::getInterfaceDescriptor());
    data.writeCString(api);
    status_t status = remote()->transact(HW_CHECK, data, &reply);
    if (status != NO_ERROR) {
        ALOGE("Error %s", strerror(-status));        
        LOGE("Error %s", strerror(-status));
        return -2000;
    } else {
        int policy = reply.readInt32();
        return policy;
    }
}


// TODO: 不懂
BpHelloWorldService::BpHelloWorldService (const sp<IBinder>& impl): BpInterface<IHelloWorldService>(impl) 
{
}

}; // namespace android