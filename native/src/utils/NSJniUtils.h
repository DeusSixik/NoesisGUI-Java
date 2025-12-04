//
// Created by Sixik on 03.12.2025.
//

#ifndef NOESIS_JNI_NSJNIUTILS_H
#define NOESIS_JNI_NSJNIUTILS_H
#include <jni.h>

#include "NsDrawing/Int32Rect.h"
#include "NsDrawing/Point.h"
#include "NsMath/Matrix.h"
#include "NsMath/Vector.h"
#include "NsRender/RenderDevice.h"


namespace Noesis {
    struct Vector2;
}

class NSJniUtils {
public:
    static void Int32RectToCopy(JNIEnv *env, Noesis::Int32Rect &src, const jobject dst) {
        const jclass cls = env->GetObjectClass(dst);
        const jfieldID xField = env->GetFieldID(cls, "x", "I");
        const jfieldID yField = env->GetFieldID(cls, "y", "I");
        const jfieldID zField = env->GetFieldID(cls, "w", "I");
        const jfieldID wField = env->GetFieldID(cls, "h", "I");

        src.x = env->GetIntField(dst, xField);
        src.y = env->GetIntField(dst, yField);
        src.width = env->GetIntField(dst, zField);
        src.height = env->GetIntField(dst, wField);

        env->DeleteLocalRef(cls);
    }

    static void Int32RectFromCopy(JNIEnv *env, const Noesis::Int32Rect &src, jobject dst) {
        const jclass cls = env->GetObjectClass(dst);
        const jfieldID xField = env->GetFieldID(cls, "x", "I");
        const jfieldID yField = env->GetFieldID(cls, "y", "I");
        const jfieldID zField = env->GetFieldID(cls, "w", "I");
        const jfieldID wField = env->GetFieldID(cls, "h", "I");

        env->SetIntField(dst, xField, src.x);
        env->SetIntField(dst, yField, src.y);
        env->SetIntField(dst, zField, src.width);
        env->SetIntField(dst, wField, src.height);

        env->DeleteLocalRef(cls);
    }

    static void Vector2ToCopy(JNIEnv *env, Noesis::Vector2 &src, const jobject dst) {
        const jclass cls = env->GetObjectClass(dst);
        const jfieldID xField = env->GetFieldID(cls, "x", "F");
        const jfieldID yField = env->GetFieldID(cls, "y", "F");

        src.x = env->GetFloatField(dst, xField);
        src.y = env->GetFloatField(dst, yField);

        env->DeleteLocalRef(cls);
    }

    static void Vector2FromCopy(JNIEnv *env, const Noesis::Vector2 &src, jobject dst) {
        const jclass cls = env->GetObjectClass(dst);
        const jfieldID xField = env->GetFieldID(cls, "x", "F");
        const jfieldID yField = env->GetFieldID(cls, "y", "F");

        env->SetFloatField(dst, xField, src.x);
        env->SetFloatField(dst, yField, src.y);

        env->DeleteLocalRef(cls);
    }

    static void PointToCopy(JNIEnv *env, Noesis::Point &src, const jobject dst) {
        const jclass cls = env->GetObjectClass(dst);
        const jfieldID xField = env->GetFieldID(cls, "x", "F");
        const jfieldID yField = env->GetFieldID(cls, "y", "F");

        src.x = env->GetFloatField(dst, xField);
        src.y = env->GetFloatField(dst, yField);

        env->DeleteLocalRef(cls);
    }

    static void PointFromCopy(JNIEnv *env, const Noesis::Point &src, jobject dst) {
        const jclass cls = env->GetObjectClass(dst);
        const jfieldID xField = env->GetFieldID(cls, "x", "F");
        const jfieldID yField = env->GetFieldID(cls, "y", "F");

        env->SetFloatField(dst, xField, src.x);
        env->SetFloatField(dst, yField, src.y);

        env->DeleteLocalRef(cls);
    }

    static void PointIToCopy(JNIEnv *env, Noesis::Pointi &src, const jobject dst) {
        const jclass cls = env->GetObjectClass(dst);
        const jfieldID xField = env->GetFieldID(cls, "x", "I");
        const jfieldID yField = env->GetFieldID(cls, "y", "I");

        src.x = env->GetIntField(dst, xField);
        src.y = env->GetIntField(dst, yField);

        env->DeleteLocalRef(cls);
    }

    static void PointIFromCopy(JNIEnv *env, const Noesis::Pointi &src, jobject dst) {
        const jclass cls = env->GetObjectClass(dst);
        const jfieldID xField = env->GetFieldID(cls, "x", "I");
        const jfieldID yField = env->GetFieldID(cls, "y", "I");

        env->SetIntField(dst, xField, src.x);
        env->SetIntField(dst, yField, src.y);

        env->DeleteLocalRef(cls);
    }

    static void Point3DToCopy(JNIEnv *env, Noesis::Point3D &src, const jobject dst) {
        const jclass cls = env->GetObjectClass(dst);
        const jfieldID xField = env->GetFieldID(cls, "x", "F");
        const jfieldID yField = env->GetFieldID(cls, "y", "F");
        const jfieldID zField = env->GetFieldID(cls, "z", "F");

        src.x = env->GetFloatField(dst, xField);
        src.y = env->GetFloatField(dst, yField);
        src.z = env->GetFloatField(dst, zField);

        env->DeleteLocalRef(cls);
    }

    static void Point3DFromCopy(JNIEnv *env, const Noesis::Point3D &src, jobject dst) {
        const jclass cls = env->GetObjectClass(dst);
        const jfieldID xField = env->GetFieldID(cls, "x", "F");
        const jfieldID yField = env->GetFieldID(cls, "y", "F");
        const jfieldID zField = env->GetFieldID(cls, "z", "F");

        env->SetFloatField(dst, xField, src.x);
        env->SetFloatField(dst, yField, src.y);
        env->SetFloatField(dst, zField, src.z);

        env->DeleteLocalRef(cls);
    }

    static void Point4DToCopy(JNIEnv *env, Noesis::Point4D &src, const jobject dst) {
        const jclass cls = env->GetObjectClass(dst);
        const jfieldID xField = env->GetFieldID(cls, "x", "F");
        const jfieldID yField = env->GetFieldID(cls, "y", "F");
        const jfieldID zField = env->GetFieldID(cls, "z", "F");
        const jfieldID wField = env->GetFieldID(cls, "w", "F");

        src.x = env->GetFloatField(dst, xField);
        src.y = env->GetFloatField(dst, yField);
        src.z = env->GetFloatField(dst, zField);
        src.w = env->GetFloatField(dst, wField);

        env->DeleteLocalRef(cls);
    }

    static void Point4DFromCopy(JNIEnv *env, const Noesis::Point4D &src, jobject dst) {
        const jclass cls = env->GetObjectClass(dst);
        const jfieldID xField = env->GetFieldID(cls, "x", "F");
        const jfieldID yField = env->GetFieldID(cls, "y", "F");
        const jfieldID zField = env->GetFieldID(cls, "z", "F");
        const jfieldID wField = env->GetFieldID(cls, "w", "F");

        env->SetFloatField(dst, xField, src.x);
        env->SetFloatField(dst, yField, src.y);
        env->SetFloatField(dst, zField, src.z);
        env->SetFloatField(dst, wField, src.w);

        env->DeleteLocalRef(cls);
    }

    static void DeviceCapsToCopy(JNIEnv *env, Noesis::DeviceCaps &src, const jobject dst) {
        const jclass cls = env->GetObjectClass(dst);
        const jfieldID centerPixelOffset = env->GetFieldID(cls, "centerPixelOffset", "F");
        const jfieldID linearRendering = env->GetFieldID(cls, "linearRendering", "Z");
        const jfieldID subpixelRendering = env->GetFieldID(cls, "subpixelRendering", "Z");
        const jfieldID depthRangeZeroToOne = env->GetFieldID(cls, "depthRangeZeroToOne", "Z");
        const jfieldID clipSpaceYInverted = env->GetFieldID(cls, "clipSpaceYInverted", "Z");

        src.centerPixelOffset = env->GetFloatField(dst, centerPixelOffset);
        src.linearRendering = env->GetBooleanField(dst, linearRendering);
        src.subpixelRendering = env->GetBooleanField(dst, subpixelRendering);
        src.depthRangeZeroToOne = env->GetBooleanField(dst, depthRangeZeroToOne);
        src.clipSpaceYInverted = env->GetBooleanField(dst, clipSpaceYInverted);

        env->DeleteLocalRef(cls);
    }

    static void DeviceCapsFromCopy(JNIEnv *env, const Noesis::DeviceCaps &src, jobject dst) {
        const jclass cls = env->GetObjectClass(dst);
        const jfieldID centerPixelOffset = env->GetFieldID(cls, "centerPixelOffset", "F");
        const jfieldID linearRendering = env->GetFieldID(cls, "linearRendering", "Z");
        const jfieldID subpixelRendering = env->GetFieldID(cls, "subpixelRendering", "Z");
        const jfieldID depthRangeZeroToOne = env->GetFieldID(cls, "depthRangeZeroToOne", "Z");
        const jfieldID clipSpaceYInverted = env->GetFieldID(cls, "clipSpaceYInverted", "Z");

        env->SetFloatField(dst, centerPixelOffset, src.centerPixelOffset);
        env->SetBooleanField(dst, linearRendering, src.linearRendering);
        env->SetBooleanField(dst, subpixelRendering, src.subpixelRendering);
        env->SetBooleanField(dst, depthRangeZeroToOne, src.depthRangeZeroToOne);
        env->SetBooleanField(dst, clipSpaceYInverted, src.clipSpaceYInverted);

        env->DeleteLocalRef(cls);
    }

    static void Matrix4ToCopy(JNIEnv *env, Noesis::Matrix4 &out, jobject jMat) {
        if (jMat == nullptr) return;

        jclass cls = env->GetObjectClass(jMat);

        jfieldID m00 = env->GetFieldID(cls, "m00", "F");
        jfieldID m01 = env->GetFieldID(cls, "m01", "F");
        jfieldID m02 = env->GetFieldID(cls, "m02", "F");
        jfieldID m03 = env->GetFieldID(cls, "m03", "F");

        jfieldID m10 = env->GetFieldID(cls, "m10", "F");
        jfieldID m11 = env->GetFieldID(cls, "m11", "F");
        jfieldID m12 = env->GetFieldID(cls, "m12", "F");
        jfieldID m13 = env->GetFieldID(cls, "m13", "F");

        jfieldID m20 = env->GetFieldID(cls, "m20", "F");
        jfieldID m21 = env->GetFieldID(cls, "m21", "F");
        jfieldID m22 = env->GetFieldID(cls, "m22", "F");
        jfieldID m23 = env->GetFieldID(cls, "m23", "F");

        jfieldID m30 = env->GetFieldID(cls, "m30", "F");
        jfieldID m31 = env->GetFieldID(cls, "m31", "F");
        jfieldID m32 = env->GetFieldID(cls, "m32", "F");
        jfieldID m33 = env->GetFieldID(cls, "m33", "F");

        float v00 = env->GetFloatField(jMat, m00);
        float v01 = env->GetFloatField(jMat, m01);
        float v02 = env->GetFloatField(jMat, m02);
        float v03 = env->GetFloatField(jMat, m03);

        float v10 = env->GetFloatField(jMat, m10);
        float v11 = env->GetFloatField(jMat, m11);
        float v12 = env->GetFloatField(jMat, m12);
        float v13 = env->GetFloatField(jMat, m13);

        float v20 = env->GetFloatField(jMat, m20);
        float v21 = env->GetFloatField(jMat, m21);
        float v22 = env->GetFloatField(jMat, m22);
        float v23 = env->GetFloatField(jMat, m23);

        float v30 = env->GetFloatField(jMat, m30);
        float v31 = env->GetFloatField(jMat, m31);
        float v32 = env->GetFloatField(jMat, m32);
        float v33 = env->GetFloatField(jMat, m33);

        out[0][0] = v00;
        out[0][1] = v01;
        out[0][2] = v02;
        out[0][3] = v03;

        out[1][0] = v10;
        out[1][1] = v11;
        out[1][2] = v12;
        out[1][3] = v13;

        out[2][0] = v20;
        out[2][1] = v21;
        out[2][2] = v22;
        out[2][3] = v23;

        out[3][0] = v30;
        out[3][1] = v31;
        out[3][2] = v32;
        out[3][3] = v33;

        // out = Noesis::Matrix4(
        //     v00, v01, v02, v03,
        //     v10, v11, v12, v13,
        //     v20, v21, v22, v23,
        //     v30, v31, v32, v33
        // );

        env->DeleteLocalRef(cls);
    }

    static void Matrix4FromCopy(JNIEnv *env, const Noesis::Matrix4 &in, jobject jMat) {
        if (jMat == nullptr) return;

        jclass cls = env->GetObjectClass(jMat);

        jfieldID m00 = env->GetFieldID(cls, "m00", "F");
        jfieldID m01 = env->GetFieldID(cls, "m01", "F");
        jfieldID m02 = env->GetFieldID(cls, "m02", "F");
        jfieldID m03 = env->GetFieldID(cls, "m03", "F");

        jfieldID m10 = env->GetFieldID(cls, "m10", "F");
        jfieldID m11 = env->GetFieldID(cls, "m11", "F");
        jfieldID m12 = env->GetFieldID(cls, "m12", "F");
        jfieldID m13 = env->GetFieldID(cls, "m13", "F");

        jfieldID m20 = env->GetFieldID(cls, "m20", "F");
        jfieldID m21 = env->GetFieldID(cls, "m21", "F");
        jfieldID m22 = env->GetFieldID(cls, "m22", "F");
        jfieldID m23 = env->GetFieldID(cls, "m23", "F");

        jfieldID m30 = env->GetFieldID(cls, "m30", "F");
        jfieldID m31 = env->GetFieldID(cls, "m31", "F");
        jfieldID m32 = env->GetFieldID(cls, "m32", "F");
        jfieldID m33 = env->GetFieldID(cls, "m33", "F");

        const Noesis::Vector4 &r0 = in[0];
        const Noesis::Vector4 &r1 = in[1];
        const Noesis::Vector4 &r2 = in[2];
        const Noesis::Vector4 &r3 = in[3];

        env->SetFloatField(jMat, m00, r0.x);
        env->SetFloatField(jMat, m01, r0.y);
        env->SetFloatField(jMat, m02, r0.z);
        env->SetFloatField(jMat, m03, r0.w);

        env->SetFloatField(jMat, m10, r1.x);
        env->SetFloatField(jMat, m11, r1.y);
        env->SetFloatField(jMat, m12, r1.z);
        env->SetFloatField(jMat, m13, r1.w);

        env->SetFloatField(jMat, m20, r2.x);
        env->SetFloatField(jMat, m21, r2.y);
        env->SetFloatField(jMat, m22, r2.z);
        env->SetFloatField(jMat, m23, r2.w);

        env->SetFloatField(jMat, m30, r3.x);
        env->SetFloatField(jMat, m31, r3.y);
        env->SetFloatField(jMat, m32, r3.z);
        env->SetFloatField(jMat, m33, r3.w);

        env->DeleteLocalRef(cls);
    }
};


#endif //NOESIS_JNI_NSJNIUTILS_H
