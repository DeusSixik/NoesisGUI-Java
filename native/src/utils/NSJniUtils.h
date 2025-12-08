//
// Created by Sixik on 03.12.2025.
//

#ifndef NOESIS_JNI_NSJNIUTILS_H
#define NOESIS_JNI_NSJNIUTILS_H
#include <jni.h>
#include <string>

#include "NsDrawing/Int32Rect.h"
#include "NsDrawing/Point.h"
#include "NsDrawing/Rect.h"
#include "NsDrawing/Thickness.h"
#include "NsGui/IUITreeNode.h"
#include "NsGui/IView.h"
#include "NsMath/Matrix.h"
#include "NsMath/Vector.h"
#include "NsRender/RenderDevice.h"


namespace Noesis {
    struct ObjectWithNameScope;
    struct Thickness;
    struct Rect;
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

    static void TessellationMaxPixelErrorToCopy(JNIEnv *env, Noesis::TessellationMaxPixelError &error,
                                                jobject javaClass) {
        if (javaClass == nullptr) return;
        const auto cls = env->GetObjectClass(javaClass);
        const auto field = env->GetFieldID(cls, "error", "F");
        error.error = env->GetFloatField(cls, field);
        env->DeleteLocalRef(cls);
    }

    static void TessellationMaxPixelErrorFromCopy(JNIEnv *env, const Noesis::TessellationMaxPixelError &error,
                                                  jobject javaClass) {
        if (javaClass == nullptr) return;
        const auto cls = env->GetObjectClass(javaClass);
        const auto field = env->GetFieldID(cls, "error", "F");

        env->SetFloatField(cls, field, error.error);

        env->DeleteLocalRef(cls);
    }

    static void ViewStatsToCopy(JNIEnv *env, Noesis::ViewStats &stats,
                                jobject javaClass) {
        if (javaClass == nullptr) return;

        jclass cls = env->GetObjectClass(javaClass);

        jfieldID frameTime = env->GetFieldID(cls, "frameTime", "F");
        jfieldID updateTime = env->GetFieldID(cls, "updateTime", "F");
        jfieldID renderTime = env->GetFieldID(cls, "renderTime", "F");
        jfieldID triangles = env->GetFieldID(cls, "triangles", "J");
        jfieldID draws = env->GetFieldID(cls, "draws", "J");
        jfieldID batches = env->GetFieldID(cls, "batches", "J");
        jfieldID tessellations = env->GetFieldID(cls, "tessellations", "J");
        jfieldID flushes = env->GetFieldID(cls, "flushes", "J");
        jfieldID geometrySize = env->GetFieldID(cls, "geometrySize", "J");
        jfieldID masks = env->GetFieldID(cls, "masks", "J");
        jfieldID opacities = env->GetFieldID(cls, "opacities", "J");
        jfieldID renderTargetSwitches = env->GetFieldID(cls, "renderTargetSwitches", "J");
        jfieldID uploadedRamps = env->GetFieldID(cls, "uploadedRamps", "J");
        jfieldID rasterizedGlyphs = env->GetFieldID(cls, "rasterizedGlyphs", "J");
        jfieldID discardedGlyphTiles = env->GetFieldID(cls, "discardedGlyphTiles", "J");

        stats.frameTime = env->GetFloatField(javaClass, frameTime);
        stats.updateTime = env->GetFloatField(javaClass, updateTime);
        stats.renderTime = env->GetFloatField(javaClass, renderTime);

        stats.triangles = static_cast<decltype(stats.triangles)>(
            env->GetLongField(javaClass, triangles));
        stats.draws = static_cast<decltype(stats.draws)>(
            env->GetLongField(javaClass, draws));
        stats.batches = static_cast<decltype(stats.batches)>(
            env->GetLongField(javaClass, batches));
        stats.tessellations = static_cast<decltype(stats.tessellations)>(
            env->GetLongField(javaClass, tessellations));
        stats.flushes = static_cast<decltype(stats.flushes)>(
            env->GetLongField(javaClass, flushes));
        stats.geometrySize = static_cast<decltype(stats.geometrySize)>(
            env->GetLongField(javaClass, geometrySize));
        stats.masks = static_cast<decltype(stats.masks)>(
            env->GetLongField(javaClass, masks));
        stats.opacities = static_cast<decltype(stats.opacities)>(
            env->GetLongField(javaClass, opacities));
        stats.renderTargetSwitches = static_cast<decltype(stats.renderTargetSwitches)>(
            env->GetLongField(javaClass, renderTargetSwitches));
        stats.uploadedRamps = static_cast<decltype(stats.uploadedRamps)>(
            env->GetLongField(javaClass, uploadedRamps));
        stats.rasterizedGlyphs = static_cast<decltype(stats.rasterizedGlyphs)>(
            env->GetLongField(javaClass, rasterizedGlyphs));
        stats.discardedGlyphTiles = static_cast<decltype(stats.discardedGlyphTiles)>(
            env->GetLongField(javaClass, discardedGlyphTiles));

        env->DeleteLocalRef(cls);
    }

    static void ViewStatsFromCopy(JNIEnv *env, const Noesis::ViewStats &stats,
                                  jobject javaClass) {
        if (javaClass == nullptr) return;
        const auto cls = env->GetObjectClass(javaClass);

        const auto frameTime = env->GetFieldID(cls, "frameTime", "F");
        const auto updateTime = env->GetFieldID(cls, "updateTime", "F");
        const auto renderTime = env->GetFieldID(cls, "renderTime", "F");
        const auto triangles = env->GetFieldID(cls, "triangles", "J");
        const auto draws = env->GetFieldID(cls, "draws", "J");
        const auto batches = env->GetFieldID(cls, "batches", "J");
        const auto tessellations = env->GetFieldID(cls, "tessellations", "J");
        const auto flushes = env->GetFieldID(cls, "flushes", "J");
        const auto geometrySize = env->GetFieldID(cls, "geometrySize", "J");
        const auto masks = env->GetFieldID(cls, "masks", "J");
        const auto opacities = env->GetFieldID(cls, "opacities", "J");
        const auto renderTargetSwitches = env->GetFieldID(cls, "renderTargetSwitches", "J");
        const auto uploadedRamps = env->GetFieldID(cls, "uploadedRamps", "J");
        const auto rasterizedGlyphs = env->GetFieldID(cls, "rasterizedGlyphs", "J");
        const auto discardedGlyphTiles = env->GetFieldID(cls, "discardedGlyphTiles", "J");

        env->SetFloatField(javaClass, frameTime, stats.frameTime);
        env->SetFloatField(javaClass, updateTime, stats.updateTime);
        env->SetFloatField(javaClass, renderTime, stats.renderTime);
        env->SetLongField(javaClass, triangles, stats.triangles);
        env->SetLongField(javaClass, draws, stats.draws);
        env->SetLongField(javaClass, batches, stats.batches);
        env->SetLongField(javaClass, tessellations, stats.tessellations);
        env->SetLongField(javaClass, flushes, stats.flushes);
        env->SetLongField(javaClass, geometrySize, stats.geometrySize);
        env->SetLongField(javaClass, masks, stats.masks);
        env->SetLongField(javaClass, opacities, stats.opacities);
        env->SetLongField(javaClass, renderTargetSwitches, stats.renderTargetSwitches);
        env->SetLongField(javaClass, uploadedRamps, stats.uploadedRamps);
        env->SetLongField(javaClass, rasterizedGlyphs, stats.rasterizedGlyphs);
        env->SetLongField(javaClass, discardedGlyphTiles, stats.discardedGlyphTiles);

        env->DeleteLocalRef(cls);
    }

    static void SizeFromCopy(JNIEnv *env, const Noesis::Size &stats,
                                  jobject javaClass) {
        if (javaClass == nullptr) return;
        const auto cls = env->GetObjectClass(javaClass);

        const auto width = env->GetFieldID(cls, "width", "F");
        const auto height = env->GetFieldID(cls, "height", "F");

        env->SetFloatField(javaClass, width, stats.width);
        env->SetFloatField(javaClass, height, stats.height);
        env->DeleteLocalRef(cls);
    }

    static void SizeToCopy(JNIEnv *env, Noesis::Size &stats,
                                  const jobject javaClass) {
        if (javaClass == nullptr) return;
        const auto cls = env->GetObjectClass(javaClass);

        const auto width = env->GetFieldID(cls, "width", "F");
        const auto height = env->GetFieldID(cls, "height", "F");

        stats.width = env->GetFloatField(javaClass, width);
        stats.height = env->GetFloatField(javaClass, height);
        env->DeleteLocalRef(cls);
    }

    static void RectFromCopy(JNIEnv *env, const Noesis::Rect &stats,
                                  jobject javaClass) {
        if (javaClass == nullptr) return;
        const auto cls = env->GetObjectClass(javaClass);

        const auto x = env->GetFieldID(cls, "x", "F");
        const auto y = env->GetFieldID(cls, "y", "F");
        const auto width = env->GetFieldID(cls, "width", "F");
        const auto height = env->GetFieldID(cls, "height", "F");

        env->SetFloatField(javaClass, x, stats.x);
        env->SetFloatField(javaClass, y, stats.y);
        env->SetFloatField(javaClass, width, stats.width);
        env->SetFloatField(javaClass, height, stats.height);
        env->DeleteLocalRef(cls);
    }

    static void RectToCopy(JNIEnv *env, Noesis::Rect &stats,
                                  const jobject javaClass) {
        if (javaClass == nullptr) return;
        const auto cls = env->GetObjectClass(javaClass);

        const auto x = env->GetFieldID(cls, "x", "F");
        const auto y = env->GetFieldID(cls, "y", "F");
        const auto width = env->GetFieldID(cls, "width", "F");
        const auto height = env->GetFieldID(cls, "height", "F");

        stats.x = env->GetFloatField(javaClass, x);
        stats.y = env->GetFloatField(javaClass, y);
        stats.width = env->GetFloatField(javaClass, width);
        stats.height = env->GetFloatField(javaClass, height);
        env->DeleteLocalRef(cls);
    }

    static void ThicknessFromCopy(JNIEnv *env, const Noesis::Thickness &stats,
                              jobject javaClass) {
        if (javaClass == nullptr) return;
        const auto cls = env->GetObjectClass(javaClass);

        const auto x = env->GetFieldID(cls, "left", "F");
        const auto y = env->GetFieldID(cls, "top", "F");
        const auto width = env->GetFieldID(cls, "right", "F");
        const auto height = env->GetFieldID(cls, "bottom", "F");

        env->SetFloatField(javaClass, x, stats.left);
        env->SetFloatField(javaClass, y, stats.top);
        env->SetFloatField(javaClass, width, stats.right);
        env->SetFloatField(javaClass, height, stats.bottom);
        env->DeleteLocalRef(cls);
    }

    static void ThicknessToCopy(JNIEnv *env, Noesis::Thickness &stats,
                                  const jobject javaClass) {
        if (javaClass == nullptr) return;
        const auto cls = env->GetObjectClass(javaClass);

        const auto x = env->GetFieldID(cls, "left", "F");
        const auto y = env->GetFieldID(cls, "top", "F");
        const auto width = env->GetFieldID(cls, "right", "F");
        const auto height = env->GetFieldID(cls, "bottom", "F");

        stats.left = env->GetFloatField(javaClass, x);
        stats.top = env->GetFloatField(javaClass, y);
        stats.right = env->GetFloatField(javaClass, width);
        stats.bottom = env->GetFloatField(javaClass, height);
        env->DeleteLocalRef(cls);
    }


    static void ObjectWithNameScopeFromCopy(JNIEnv *env, const Noesis::ObjectWithNameScope &stats,
                              jobject javaClass) {
        if (javaClass == nullptr) return;
        const auto cls = env->GetObjectClass(javaClass);

        const auto x = env->GetFieldID(cls, "object_ptr", "L");
        const auto y = env->GetFieldID(cls, "object_ptr", "L");

        env->SetLongField(javaClass, x, reinterpret_cast<jlong>(stats.object));
        env->SetLongField(javaClass, y, reinterpret_cast<jlong>(stats.scope));
        env->DeleteLocalRef(cls);
    }

    static jobject createJavaObject(JNIEnv* env, const std::string& className, jlong ptr) {
        // Заменяем точки на слеши для JNI
        std::string jniClassName = className;
        for (char& c : jniClassName) {
            if (c == '.') c = '/';
        }

        // Находим класс
        jclass clazz = env->FindClass(jniClassName.c_str());
        if (!clazz) {
            // Можно добавить обработку ошибок
            return nullptr;
        }

        // Находим конструктор <init>(J)
        jmethodID constructor = env->GetMethodID(clazz, "<init>", "(J)V");
        if (!constructor) {
            env->DeleteLocalRef(clazz);
            return nullptr;
        }

        // Создаем объект
        jobject obj = env->NewObject(clazz, constructor, ptr);

        // Освобождаем локальную ссылку на класс
        env->DeleteLocalRef(clazz);

        return obj;
    }
};


#endif //NOESIS_JNI_NSJNIUTILS_H
