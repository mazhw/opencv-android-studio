#include <jni.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/features2d/features2d.hpp>

using namespace std;
using namespace cv;

extern "C" JNIEXPORT jstring JNICALL Java_com_seventythree_cvtest_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

/**
 * @brief 使用Canndy算子检测图像中的对象轮廓
 * @param matAddrGray, Mat图像的内存地址
 */
extern "C" JNIEXPORT void JNICALL Java_com_seventythree_cvtest_MainActivity_CanndyDetect(
        JNIEnv *env,
        jobject thiz,
        jlong matAddrGray) {
    Mat &grayMat = *(Mat *) matAddrGray;
    Canny(grayMat, grayMat, 50, 100);
}

