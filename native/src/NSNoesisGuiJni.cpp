//
// Created by Sixik on 04.12.2025.
//

#include <jni.h>
#include <jni_md.h>

#include "NsGui/IntegrationAPI.h"
#include "NsMath/AABBox.h"

extern "C" {

    JNIEXPORT jlong JNICALL
    Java_dev_sixik_noesisgui_NoesisGui_nativeParseXaml(JNIEnv* env, jclass, jstring xamlCode) {
        if (xamlCode == nullptr) return 0;

        const char* nativeCode = env->GetStringUTFChars(xamlCode, nullptr);
        if (!nativeCode) return 0;

        Noesis::Ptr<Noesis::BaseComponent> root;
        try {
            root = Noesis::GUI::ParseXaml(nativeCode);
        } catch (...) {
            env->ReleaseStringUTFChars(xamlCode, nativeCode);
            return 0;
        }

        env->ReleaseStringUTFChars(xamlCode, nativeCode);

        Noesis::BaseComponent* ptr = root.GetPtr();
        if (ptr != nullptr) {
            // Увеличиваем refcount, чтобы объект жил после уничтожения Ptr
            ptr->AddReference();
        }

        // root выходит из области видимости -> Release() -> refcount--,
        // но мы только что сделали AddReference(), так что объект остаётся жив.
        return reinterpret_cast<jlong>(ptr);
    }
}
