#ifndef ANDROID_HELLO_WORLD_SERVICE_H
#define ANDROID_HELLO_WORLD_SERVICE_H

#define LOG_TAG "HelloWorldService"

#include <helloworld/BnHelloWorldService.h>
#include <map>
#include <string>

namespace android {

class HelloWorldService : public BnHelloWorldService {
    
public:
    static void instantiate();
    
    virtual int helloWorld(const char *str);
    virtual int check(const char *resourceType);
    virtual int setAccessFlag(const char *resourceType, int accessFlag);

    //调用BnHelloWorldService的onTransact()方法
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags);

    // 保存一个map<resourceType,accessFlag>
    // static就报错？
    std::map<std::string, int> rules;


private:
    HelloWorldService();
    virtual ~HelloWorldService();

};


}; // namespace android

#endif