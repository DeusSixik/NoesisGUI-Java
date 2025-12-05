//
// Created by Sixik on 05.12.2025.
//

#include <jni.h>

#include "NsGui/FrameworkElement.h"

namespace Noesis {
    struct IRenderer;
}

extern "C" {

    static Noesis::FrameworkElement *getComponent(JNIEnv *env, const jlong handle) {
        if (handle == 0) {
            jclass excCls = env->FindClass("java/lang/IllegalStateException");
            if (excCls != nullptr) {
                env->ThrowNew(excCls, "Noesis.FrameworkElement ptr is null");
            }
            return nullptr;
        }
        return reinterpret_cast<Noesis::FrameworkElement *>(handle);
    }

}
