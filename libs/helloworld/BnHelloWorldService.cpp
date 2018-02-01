#include <helloworld/BnHelloWorldService.h>
#include <binder/Parcel.h>

namespace android {

// Override the onTransact()
status_t BnHelloWorldService::onTransact(uint32_t code, const Parcel &data, Parcel *reply, uint32_t flags) {
    switch(code) {

        case HW_HELLOWORLD: {
            // 确认正确的服务请求
            CHECK_INTERFACE(IHelloWorldService, data, reply);
            const char *str;
            // read the string from the client，data中存放client发送的数据
            str = data.readCString();
            // 调用输出方法, 返回值保存到reply中
            reply->writeInt32(helloWorld(str));
            // IHelloWorldService::helloWorld(),具体实现？
            return NO_ERROR;
        } break;

        // 服务端实际处理的函数
        case HW_CHECK: {
            // 确认正确的服务请求
            CHECK_INTERFACE(IHelloWorldService, data, reply);
            const char *api;
            // 读取客户端发送的参数，但是对于传感器怎么办，在SensorService中判断type之后再返回？将type添加到api:resource中
            api = data.readCString();
            // 调用输出方法, 返回值保存到reply中
            // 这里就需要判断了，返回-1,0,1,2
            reply->writeInt32(check(api));
            return NO_ERROR;
        } break;

        // 更新规则
        case HW_SET_FLAG: {
            // 确认正确的服务请求
            CHECK_INTERFACE(IHelloWorldService, data, reply);
            const char *resourceType;
            int accessFlag;
            // 读取客户端发送的参数，data有两个参数怎么办？？？？？？？？？？？？？？？？
            resourceType = data.readCString();
            accessFlag = data.readInt32();
            // 调用输出方法, 返回值保存到reply中
            reply->writeInt32(setAccessFlag(resourceType, accessFlag));
            return NO_ERROR;
        } break;

        default:
            return BBinder::onTransact(code, data, reply, flags);
    }

}

}; // namespace anrdoid