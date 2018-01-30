# HelloWorldService
Native Service Demo

###参考Android框架解密

位于android4.2.2_r1/frameworks/native/目录下<br>
还没有实现对HelloWorldManager的封装，所以在cmds/main_helloworldclient.cpp中使用系统服务很麻烦。<br>

###启动Service和Client
####Service
```
adb shell
su
service list
helloworldservice &
```
####Client
```
helloworldclient &
```

