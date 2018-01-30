#include <helloworld/IHelloWorldService.h>
// 这个头文件
#include <helloworld/BpHelloWorldService.h>

namespace android {

// 接口宏
// TODO：这儿到底是IHelloWorldService还是HelloWorldService??
IMPLEMENT_META_INTERFACE(HelloWorldService, "android.capsane.IHelloWorldService");
// IMPLEMENT_META_INTERFACE(HelloWorldService, "helloworldservice");

}; // namespace android