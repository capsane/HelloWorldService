# HelloWorldService
Native Service Demo

### 参考Android框架解密

位于android4.2.2_r1/frameworks/native/目录下<br>
还没有实现对HelloWorldManager的封装，所以在cmds/main_helloworldclient.cpp中使用系统服务很麻烦。<br>

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
int policy = mHelloWorldManger.check("getPicture");

```

#### init.rc
注册Service
设置Boot启动：on

#### Singleton
单例模式的使用不知到会不会出问题<br>

#### Thread
线程安全<br>
当有众多的API需要访问服务<br>


## TOOD
  1.init.rc<br>
  2.单例模式<br>
  3.线程安全<br>
