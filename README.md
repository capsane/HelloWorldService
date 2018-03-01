# HelloWorldService
A Native Service Demo

## 参考《Android框架揭密》
源码位于android4.2.2_r1/frameworks/native/目录下<br>
### 代码目录
	cmds/hellod: main_helloworldclient.cpp, main_helloworldservice.cpp<br>
	include/helloworld: *.h<br>
	libs/helloworld: BnHelloWorldService, BpHelloWorldService, HelloWorldManager, HelloWorldService, IHelloWorldService. <br>

## 编写Native Service


#### HelloWorldManager
客户端封装为HelloWorldManager类，使用：
```cpp
#include "HelloWorldManger.h"

HelloWorldManager mHelloWorldManager;
int policy = mHelloWorldManger.check("TAKE_PICTURE");

```

### 手动启动Service
#### Service

main_helloworldservice.cpp<br>

```cpp
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
    HelloWorldService::instantiate();
    // 创建线程池
    ProcessState::self()->startThreadPool();
    LOGI("HelloWorldService is starting now");
    // 在线程池中等待接收client请求
    IPCThreadState::self()->joinThreadPool();
    return 0;
}
```

编译为可执行程序，会自动添加到源码的system/bin/目录中。<br>
在terminal启动服务<br>
```
adb shell
su
service list
helloworldservice &
```

## 开机启动native service
#### system_init()
init1()调用system_init()，启动SurfaceFlinger、AudioFlinger、MediaPlayerService、CameraService、SensorService等本地服务。<br>
CameraService不是由mediaserver启动的吗？答案：《Android框架揭秘》P157中确实启动了前四个服务，但是在api17中却只启动了SurfaceFlinger和SensorService两个服务。<br>

system_init.cpp<br>
```cpp
#inlcude <HelloWorldService.h>
// Line72
SensorService::instantiate();
HelloWorldService::instantiate();
```

Android.mk<br>
```mk
LOCAL_C_INCLUDES := \
    $(native)/include/helloworld \
    external/stlport/stlport \
    bionic

LOCAL_STATIC_LIBRARIES := libstlport_static

LOCAL_SHARED_LIBRARIES := \
    libhelloworld
```


## TOOD
  1.单例模式<br>
  2.线程安全<br>
