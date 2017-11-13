#include <jni.h>
#include <string>
#include "pngquant.c"
#include <android/log.h>
#include <stdio.h>
#define LOGE(...) \
  ((void)__android_log_print(ANDROID_LOG_ERROR, "compress::", __VA_ARGS__))



extern "C"
JNIEXPORT jboolean
JNICALL Java_io_haydar_pngquantandroid_PNGQuantAndroid_compressImage(
        JNIEnv* env,
        jobject instance,
        jstring inputImagePath_,
        jstring outputImagePath_) {

    const char *inputImagePath = env->GetStringUTFChars(inputImagePath_, 0);
    const char *outputImagePath = env->GetStringUTFChars(outputImagePath_, 0);



    pngquant_file(inputImagePath, outputImagePath);
    return true;
}

