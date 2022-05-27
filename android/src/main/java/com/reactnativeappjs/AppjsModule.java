package com.reactnativeappjs;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.JavaScriptContextHolder;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;
import com.facebook.soloader.SoLoader;

@ReactModule(name = AppjsModule.NAME)
public class AppjsModule extends ReactContextBaseJavaModule {
    public static final String NAME = "Appjs";

    public AppjsModule(ReactApplicationContext reactContext) {
        super(reactContext);
    }

    @Override
    @NonNull
    public String getName() {
        return NAME;
    }

    @ReactMethod(isBlockingSynchronousMethod = true)
    public void install() {
        SoLoader.loadLibrary("reactnativeappjs");
        JavaScriptContextHolder jsContext = getReactApplicationContext().getJavaScriptContextHolder();
        nativeInstall(jsContext.get());
    }

    private static native void nativeInstall(long jsiPtr);

}
