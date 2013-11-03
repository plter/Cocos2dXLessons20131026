#include <jni.h>
#include "cn_eoe_hellojni_JNI.h"
#include <string.h>
#include <stdio.h>
#include "Math.h"

/*
 * Class:     cn_eoe_hellojni_JNI
 * Method:    getNum
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_cn_eoe_hellojni_JNI_getNum
  (JNIEnv *, jobject){
	return 2;
}

/*
 * Class:     cn_eoe_hellojni_JNI
 * Method:    getString
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cn_eoe_hellojni_JNI_getString
  (JNIEnv *env, jobject jthis){
	jclass jc = env->FindClass("cn/eoe/hellojni/JNI");
	jmethodID mid = env->GetMethodID(jc,"getInt","()I");
	int intVar = env->CallIntMethod(jthis,mid);

	char buf[20];
	sprintf(buf,"Hello %d\0",intVar);
	return env->NewStringUTF(buf);
}

/*
 * Class:     cn_eoe_hellojni_JNI
 * Method:    sayHi
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_cn_eoe_hellojni_JNI_sayHi
  (JNIEnv *, jclass){
}


/*
 * Class:     cn_eoe_hellojni_JNI
 * Method:    max
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_cn_eoe_hellojni_JNI_max
  (JNIEnv *, jobject, jint a, jint b){
	return Math::max(a,b);
}
