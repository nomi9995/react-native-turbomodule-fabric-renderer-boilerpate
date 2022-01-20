#include "MyApplicationTurboModuleManagerDelegate.h"

#include "MyApplicationModuleProvider.h"
#include "MyApplicationTurboCxxModule.h"

namespace facebook {
namespace react {

jni::local_ref<MyApplicationTurboModuleManagerDelegate::jhybriddata>
MyApplicationTurboModuleManagerDelegate::initHybrid(jni::alias_ref<jhybridobject>) {
  return makeCxxInstance();
}

void MyApplicationTurboModuleManagerDelegate::registerNatives() {
  registerHybrid({
      makeNativeMethod(
          "initHybrid", MyApplicationTurboModuleManagerDelegate::initHybrid),
      makeNativeMethod(
          "canCreateTurboModule",
          MyApplicationTurboModuleManagerDelegate::canCreateTurboModule),
  });
}

std::shared_ptr<TurboModule> MyApplicationTurboModuleManagerDelegate::getTurboModule(
    const std::string name,
    const std::shared_ptr<CallInvoker> jsInvoker) {
  if (name == "MyApplicationTurboCxxModule") { return std::make_shared<MyApplicationTurboCxxModule>(jsInvoker); }
  return nullptr;
}

std::shared_ptr<TurboModule> MyApplicationTurboModuleManagerDelegate::getTurboModule(
    const std::string name,
    const JavaTurboModule::InitParams &params) {
  return MyApplicationModuleProvider(name, params);
}

bool MyApplicationTurboModuleManagerDelegate::canCreateTurboModule(
    std::string name) {
  return getTurboModule(name, nullptr) != nullptr ||
      getTurboModule(name, {.moduleName = name}) != nullptr;
}

} // namespace react
} // namespace facebook
