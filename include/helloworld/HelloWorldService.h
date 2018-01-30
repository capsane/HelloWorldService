#ifndef ANDROID_HELLO_WORLD_SERVICE_H
#define ANDROID_HELLO_WORLD_SERVICE_H

#define LOG_TAG "HelloWorldService"

#include <helloworld/BnHelloWorldService.h>

namespace android {

class HelloWorldService : public BnHelloWorldService {
    
public:
    static void instantiate();
    // helloworld()为什么在这里声明？在BnHelloWorldService.cpp中调用了这个函数啊
    virtual int helloWorld(const char *str);
    virtual int check(const char *api);

    //调用BnHelloWorldService的onTransact()方法
    virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags);


private:
    HelloWorldService();
    virtual ~HelloWorldService();

};


}; // namespace android

#endif