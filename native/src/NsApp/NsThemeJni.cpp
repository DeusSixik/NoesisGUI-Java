//
// Created by Sixik on 04.12.2025.
//

#include <jni.h>
#include <jni_md.h>

#include "NsGui/Uri.h"
#include "App/Theme/Include/NsApp/ThemeProviders.h"

using namespace Noesis;
using namespace NoesisApp;

static Uri *MakeThemeUri(Noesis::Uri (*fn)()) {
    const Uri uri = fn();
    return new Uri(uri);
}

extern "C" {
JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeDarkRed(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::DarkRed));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeLightRed(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::LightRed));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeDarkGreen(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::DarkGreen));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeLightGreen(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::LightGreen));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeDarkBlue(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::DarkBlue));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeLightBlue(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::LightBlue));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeDarkOrange(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::DarkOrange));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeLightOrange(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::LightOrange));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeDarkEmerald(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::DarkEmerald));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeLightEmerald(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::LightEmerald));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeDarkPurple(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::DarkPurple));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeLightPurple(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::LightPurple));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeDarkCrimson(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::DarkCrimson));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeLightCrimson(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::LightCrimson));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeDarkLime(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::DarkLime));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeLightLime(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::LightLime));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeDarkAqua(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::DarkAqua));
}

JNIEXPORT jlong JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeLightAqua(JNIEnv *, jclass) {
    return reinterpret_cast<jlong>(MakeThemeUri(&Theme::LightAqua));
}

JNIEXPORT void JNICALL
Java_dev_sixik_noesisgui_1impl_NSThemes_nativeDestroy(JNIEnv *, jclass, jlong ptr) {
    delete reinterpret_cast<Uri *>(ptr);
}
} // extern "C"
