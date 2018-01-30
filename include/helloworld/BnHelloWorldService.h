#ifndef ANDROID_BN_HELLO_WORLD_SERVICE_H
#define ANDROID_BN_HELLO_WORLD_SERVICE_H

#include <binder/Parcel.h>
#include <helloworld/IHelloWorldService.h>

namespace android {

    class BnHelloWorldService: public BnInterface<IHelloWorldService> {

        public:
        // Redefine the onTransact() method of BBinder
        virtual status_t onTransact(uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags = 0);

    };

}; // namespace android

#endif