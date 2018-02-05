#include <binder/IServiceManager.h>
#include <binder/IPCThreadState.h>
#include <helloworld/HelloWorldService.h>
#include <helloworld/BnHelloWorldService.h>
#include <utils/Log.h>


#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)  

using namespace std;

namespace android {

void HelloWorldService::instantiate() {
    // 注册服务到系统中
    LOGI("trying to add service...");
    defaultServiceManager()->addService(
        String16("android.capsane.IHelloWorldService"), new HelloWorldService());
        // String16("helloworldservice"), new HelloWorldService());

}

int HelloWorldService::helloWorld(const char* str) {
    LOGI("%s\n", str);
    return 1000;
}

// 
int HelloWorldService::check(const char* rresourceType) {
    /**
     * 根据resourceType，查找map，返回对应的accessFlag
     *
     */
    string resourceType = rresourceType;
    LOGI("check(%s)\n", rresourceType);
    map<string, int>::iterator iter;
    iter = rules.find(resourceType);
    if (iter == rules.end()) {
        LOGI("get   Cannot find the resourceType: %s\n", rresourceType);
        return -1;
    }
    int accessFlag = iter->second;
    LOGI("Get the %s is %d\n", rresourceType, accessFlag);
    return accessFlag;
}

// APP更改rules
int HelloWorldService::setAccessFlag(const char* rresourceType, int accessFlag) {
    LOGI("setAccessFlag(%s,%d)\n", rresourceType, accessFlag);
    /**
     * 根据resourceType, 设置map中对应的value 
     */
    string resourceType = rresourceType;
    map<string, int>::iterator iter;
    iter = rules.find(resourceType);
    if (iter == rules.end()) {
        LOGI("set   Cannot find the resourceType: %s\n", rresourceType);
        return -1;
    }
    iter->second = accessFlag;
    LOGI("Set the %s to %d\n", rresourceType, accessFlag);
    return 0;
}


HelloWorldService::HelloWorldService() {
    LOGI("HelloWorldService is created");
    string resources[21] = {"TAKE_PICTURE","START_RECORDING","START_PREVIEW","START_RECORD","STOP_RECORD","START_AUDIO","STOP_AUDIO","CONTROL_VOLUME",
    "SENSOR_TYPE_ACCELEROMETER","SENSOR_TYPE_GYROSCOPE","SENSOR_TYPE_PRESSURE","SENSOR_TYPE_TEMPERATURE","SENSOR_TYPE_PROXIMITY","SENSOR_TYPE_LIGHT",
    "SENSOR_TYPE_GRAVITY","SENSOR_TYPE_MAGNETIC_FIELD","SENSOR_TYPE_ORIENTATION","SENSOR_TYPE_LINEAR_ACCELERATION",
    "SENSOR_TYPE_ROTATION_VECTOR", "SENSOR_TYPE_RELATIVE_HUMIDITY", "SENSOR_TYPE_AMBIENT_TEMPERATURE"};
    int len = sizeof(resources) / sizeof(resources[0]);
    for (int i = 0; i < 21; i++) {
        string str = resources[i];
        rules.insert(pair<string,int>(str,0));
        LOGI("%s,%d\n",str.c_str(), 0);
    }
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
