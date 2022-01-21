#include <fbjni/fbjni.h>
#include "MyApplicationTurboModuleManagerDelegate.h"

JNIEXPORT jint JNICALL JNI_OnLoad(JavaVM *vm, void *) {
  return facebook::jni::initialize(vm, [] {
    facebook::react::MyApplicationTurboModuleManagerDelegate::registerNatives();
  });
}
