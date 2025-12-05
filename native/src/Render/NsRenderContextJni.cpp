#include <jni.h>
#include <vector>

#include <NsCore/Ptr.h>
#include <NsGui/Image.h>

#include "Render/RenderContext/Include/NsRender/RenderContext.h"


    // Удобный helper для конвертации jlong -> RenderContext*
    static inline NoesisApp::RenderContext *fromHandle(jlong handle) {
        return reinterpret_cast<NoesisApp::RenderContext *>(handle);
    }

    // Если хочешь — можешь сделать безопасный Destroy через Release()
    static inline void destroyContext(NoesisApp::RenderContext *ctx) {
        if (ctx != nullptr) {
            // Вариант 1: если RenderContext наследует BaseComponent с AddRef/Release:
            ctx->Release();

            // Либо, если у тебя есть хелпер из NoesisApp:
            // NsRelease(ctx);
        }
    }

    extern "C" {
    // ================== STATIC ==================

    // private static native long nCreate();
    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nCreate(JNIEnv *env, jclass clazz) {
        Noesis::Ptr<NoesisApp::RenderContext> ctx = NoesisApp::RenderContext::Create();
        // Перекладываем владение в "сырой" указатель для Java
        NoesisApp::RenderContext *raw = ctx.GiveOwnership();
        return reinterpret_cast<jlong>(raw);
    }

    // private static native long nCreateByName(String name);
    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nCreateByName(JNIEnv *env, jclass clazz,
                                                                      jstring jname) {
        if (jname == nullptr) return 0;

        const char *name = env->GetStringUTFChars(jname, nullptr);
        Noesis::Ptr<NoesisApp::RenderContext> ctx = NoesisApp::RenderContext::Create(name);
        env->ReleaseStringUTFChars(jname, name);

        NoesisApp::RenderContext *raw = ctx.GiveOwnership();
        return reinterpret_cast<jlong>(raw);
    }

    // private static native long nCurrent();
    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nCurrent(JNIEnv *env, jclass clazz) {
        NoesisApp::RenderContext *ctx = NoesisApp::RenderContext::Current();
        return reinterpret_cast<jlong>(ctx);
    }

    // private static native void nDestroy(long ptr);
    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nDestroy(JNIEnv *env, jclass clazz,
                                                                 jlong handle) {
        destroyContext(fromHandle(handle));
    }

    // ================== INSTANCE ==================

    // private static native String nGetDescription(long ptr);
    JNIEXPORT jstring JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nGetDescription(JNIEnv *env, jclass clazz,
                                                                        jlong handle) {
        NoesisApp::RenderContext *ctx = fromHandle(handle);
        if (!ctx) return nullptr;

        const char *desc = ctx->Description();
        return desc ? env->NewStringUTF(desc) : nullptr;
    }

    // private static native String nGetShaderLang(long ptr);
    JNIEXPORT jstring JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nGetShaderLang(JNIEnv *env, jclass clazz,
                                                                       jlong handle) {
        NoesisApp::RenderContext *ctx = fromHandle(handle);
        if (!ctx) return nullptr;

        const char *lang = ctx->ShaderLang();
        return lang ? env->NewStringUTF(lang) : nullptr;
    }

    // private static native int nGetScore(long ptr);
    JNIEXPORT jint JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nGetScore(JNIEnv *, jclass,
                                                                  jlong handle) {
        NoesisApp::RenderContext *ctx = fromHandle(handle);
        if (!ctx) return 0;
        return static_cast<jint>(ctx->Score());
    }

    // private static native boolean nValidate(long ptr);
    JNIEXPORT jboolean JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nValidate(JNIEnv *, jclass,
                                                                  jlong handle) {
        NoesisApp::RenderContext *ctx = fromHandle(handle);
        if (!ctx) return JNI_FALSE;
        return ctx->Validate() ? JNI_TRUE : JNI_FALSE;
    }

    // private static native void nInit(long ptr, long windowPtr, int[] samplesInOut,
    //                                  boolean vsync, boolean sRGB);
    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nInit(JNIEnv *env, jclass,
                                                              jlong handle, jlong windowPtr,
                                                              jintArray jSamples,
                                                              jboolean jVsync,
                                                              jboolean jSRGB) {
        NoesisApp::RenderContext *ctx = fromHandle(handle);
        if (!ctx) return;

        void *window = reinterpret_cast<void *>(windowPtr);

        uint32_t samples = 0;
        if (jSamples != nullptr && env->GetArrayLength(jSamples) > 0) {
            jint tmp;
            env->GetIntArrayRegion(jSamples, 0, 1, &tmp);
            if (tmp < 0) tmp = 0;
            samples = static_cast<uint32_t>(tmp);
        }

        bool vsync = (jVsync == JNI_TRUE);
        bool sRGB = (jSRGB == JNI_TRUE);

        ctx->Init(window, samples, vsync, sRGB);

        // записываем обратно изменённое значение samples
        if (jSamples != nullptr && env->GetArrayLength(jSamples) > 0) {
            jint out = static_cast<jint>(samples);
            env->SetIntArrayRegion(jSamples, 0, 1, &out);
        }
    }

    // private static native void nShutdown(long ptr);
    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nShutdown(JNIEnv *, jclass,
                                                                  jlong handle) {
        NoesisApp::RenderContext *ctx = fromHandle(handle);
        if (!ctx) return;
        ctx->Shutdown();
    }

    // private static native void nSetWindow(long ptr, long windowPtr);
    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nSetWindow(JNIEnv *, jclass,
                                                                   jlong handle,
                                                                   jlong windowPtr) {
        NoesisApp::RenderContext *ctx = fromHandle(handle);
        if (!ctx) return;

        void *window = reinterpret_cast<void *>(windowPtr);
        ctx->SetWindow(window);
    }

    // private static native void nSaveState(long ptr);
    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nSaveState(JNIEnv *, jclass,
                                                                   jlong handle) {
        NoesisApp::RenderContext *ctx = fromHandle(handle);
        if (!ctx) return;
        ctx->SaveState();
    }

    // private static native void nBeginRender(long ptr);
    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nBeginRender(JNIEnv *, jclass,
                                                                     jlong handle) {
        NoesisApp::RenderContext *ctx = fromHandle(handle);
        if (!ctx) return;
        ctx->BeginRender();
    }

    // private static native void nEndRender(long ptr);
    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nEndRender(JNIEnv *, jclass,
                                                                   jlong handle) {
        NoesisApp::RenderContext *ctx = fromHandle(handle);
        if (!ctx) return;
        ctx->EndRender();
    }

    // private static native void nResize(long ptr);
    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nResize(JNIEnv *, jclass,
                                                                jlong handle) {
        NoesisApp::RenderContext *ctx = fromHandle(handle);
        if (!ctx) return;
        ctx->Resize();
    }

    // private static native float nGetGpuTimeMs(long ptr);
    JNIEXPORT jfloat JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nGetGpuTimeMs(JNIEnv *, jclass,
                                                                      jlong handle) {
        NoesisApp::RenderContext *ctx = fromHandle(handle);
        if (!ctx) return 0.0f;
        return ctx->GetGPUTimeMs();
    }

    // private static native void nSetClearColor(long ptr, float r, float g, float b, float a);
    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nSetClearColor(JNIEnv *, jclass,
                                                                       jlong handle,
                                                                       jfloat r, jfloat g,
                                                                       jfloat b, jfloat a) {
        NoesisApp::RenderContext *ctx = fromHandle(handle);
        if (!ctx) return;
        ctx->SetClearColor(r, g, b, a);
    }

    // private static native void nSetDefaultRenderTarget(long ptr,
    //                                                    int width, int height,
    //                                                    boolean doClearColor);
    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nSetDefaultRenderTarget(JNIEnv *, jclass,
        jlong handle,
        jint width,
        jint height,
        jboolean jDoClear) {
        NoesisApp::RenderContext *ctx = fromHandle(handle);
        if (!ctx) return;

        bool doClear = (jDoClear == JNI_TRUE);
        ctx->SetDefaultRenderTarget(static_cast<uint32_t>(width),
                                    static_cast<uint32_t>(height),
                                    doClear);
    }

    // private static native void nSwap(long ptr);
    JNIEXPORT void JNICALL
    Java_dev_sixik_noesisgui_nsrenderer_NSRenderContext_nSwap(JNIEnv *, jclass,
                                                              jlong handle) {
        NoesisApp::RenderContext *ctx = fromHandle(handle);
        if (!ctx) return;
        ctx->Swap();
    }

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_render_NSRenderContext_nCreatePixelShader(JNIEnv *env, jclass,
                                                                       jlong ctxHandle,
                                                                       jstring jlabel,
                                                                       jbyte jshader,
                                                                       jbyteArray jcode) {
        NoesisApp::RenderContext *ctx = fromHandle(ctxHandle);
        if (!ctx) return 0;

        const char *label = nullptr;
        if (jlabel != nullptr) {
            label = env->GetStringUTFChars(jlabel, nullptr);
        }

        std::vector<uint8_t> buffer;
        if (jcode != nullptr) {
            jsize len = env->GetArrayLength(jcode);
            buffer.resize(len);
            env->GetByteArrayRegion(jcode, 0, len,
                                    reinterpret_cast<jbyte *>(buffer.data()));
        }

        Noesis::ArrayRef<uint8_t> codeRef;
        if (!buffer.empty()) {
            codeRef = Noesis::ArrayRef<uint8_t>(buffer.data(), buffer.size());
        }

        uint8_t shaderByte = static_cast<uint8_t>(jshader);
        void *shaderPtr = ctx->CreatePixelShader(label, shaderByte, codeRef);

        if (jlabel != nullptr) {
            env->ReleaseStringUTFChars(jlabel, label);
        }

        return reinterpret_cast<jlong>(shaderPtr);
    }
    } // extern "C"

