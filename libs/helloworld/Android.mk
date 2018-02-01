LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	IHelloWorldService.cpp \
	BnHelloWorldService.cpp \
	BpHelloWorldService.cpp \
	HelloWorldService.cpp \
	HelloWorldManager.cpp

LOCAL_SHARED_LIBRARIES := \
	libbinder \
	libcutils \
	libutils 

# capsane: to use std:map
LOCAL_C_INCLUDES := \
	external/stlport/stlport \
	bionic \

LOCAL_STATIC_LIBRARIES := libstlport_static 

LOCAL_PRELINK_MODULE := false

LOCAL_CERTIFICATE := platform

LOCAL_MODULE:= libhelloworld


include $(BUILD_SHARED_LIBRARY)

