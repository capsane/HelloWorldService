LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	main_helloworldservice.cpp 

LOCAL_SHARED_LIBRARIES := \
	libbinder \
	libhelloworld \
	libutils

base := $(LOCAL_PATH)/../..

# STL
LOCAL_C_INCLUDES := \
	external/stlport/stlport \
	bionic \

LOCAL_STATIC_LIBRARIES := libstlport_static 



LOCAL_MODULE:= helloworldservice

include $(BUILD_EXECUTABLE)

###########################################################################

include $(CLEAR_VARS)

LOCAL_SRC_FILES:= \
	main_helloworldclient.cpp 

LOCAL_SHARED_LIBRARIES := \
	libbinder \
	libhelloworld \
	libutils

base := $(LOCAL_PATH)/../..

LOCAL_MODULE:= helloworldclient

include $(BUILD_EXECUTABLE)

