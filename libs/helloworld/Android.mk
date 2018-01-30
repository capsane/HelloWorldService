LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	IHelloWorldService.cpp \
	BnHelloWorldService.cpp \
	BpHelloWorldService.cpp \
	HelloWorldService.cpp

LOCAL_SHARED_LIBRARIES := \
	libbinder \
	libcutils \
	libutils 

LOCAL_PRELINK_MODULE := false

LOCAL_MODULE:= libhelloworld


include $(BUILD_SHARED_LIBRARY)

