package com.reactnativeturbomodulefabricrendererboilerpate;

import com.facebook.react.ReactActivity;
import com.facebook.react.ReactActivityDelegate;
import com.facebook.react.ReactRootView;

public class MainActivity extends ReactActivity {

  /**
   * Returns the name of the main component registered from JavaScript. This is used to schedule
   * rendering of the component.
   */
  @Override
  protected String getMainComponentName() {
    return "ReactNativeTurbomoduleFabricRendererBoilerpate";
  }

  // Add the Activity Delegate, if you don't have one already.
  public static class MainActivityDelegate extends ReactActivityDelegate {

    public MainActivityDelegate(ReactActivity activity, String mainComponentName) {
      super(activity, mainComponentName);
    }

    @Override
    protected ReactRootView createRootView() {
      ReactRootView reactRootView = new ReactRootView(getContext());

      // Make sure to call setIsFabric(true) on your ReactRootView
      reactRootView.setIsFabric(true);
      return reactRootView;
    }
  }

  // Make sure to override the `createReactActivityDelegate()` method.
  @Override
  protected ReactActivityDelegate createReactActivityDelegate() {
    return new MainActivityDelegate(this, getMainComponentName());
  }
}
