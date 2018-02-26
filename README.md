# HelloWorldService
Native Service Demo

### 参考Android框架解密

位于android4.2.2_r1/frameworks/native/目录下<br>

### 启动Service和Client
#### Service
```
adb shell
su
service list
helloworldservice &
```
#### Client
```
helloworldclient &
```

#### HelloWorldManager
客户端封装为HelloWorldManager类，使用：
```cpp
#include "HelloWorldManger.h"

HelloWorldManager mHelloWorldManager;
int policy = mHelloWorldManger.check("TAKE_PICTURE");

```

#### init.rc
放弃在init.rc中启动添加的native service<br>

#### Singleton
单例模式的使用不知到会不会出问题<br>

#### Thread
线程安全<br>
当有众多的API需要访问服务<br>

###开机启动native service
####system_init()
init1()函数调用system_init()函数，启动SurfaceFlinger、AudioFlinger、MediaPlayerService、CameraService、SensorService等本地服务<br>
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
