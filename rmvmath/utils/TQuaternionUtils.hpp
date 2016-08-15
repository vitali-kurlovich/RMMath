//
// Created by Vitali Kurlovich on 8/5/16.
//

#ifndef RMVECTORMATH_TQUATERNIONUTILS_HPP
#define RMVECTORMATH_TQUATERNIONUTILS_HPP

#include <cmath>

#include "common/common.hpp"

#include "complex/quaternion/TQuaternion_def.hpp"
#include "matrix/matrix3x3/TMatrix3x3_def.hpp"
#include "matrix/affinematrix4x4/TAffineMatrix4x4_def.hpp"
#include "vector/vector3x/TVector3_def.hpp"


#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

namespace rmmath {

    namespace utils {

        template<typename T>
        const complex::TQuaternion<T> rotationQuaternion(const T angle, const vector::TVector3<T> &axis) {

#ifdef RM_MATH_STAT
            RM_STAT_MUL(3)
#endif

            const T half_angle(angle * (T) 0.5);
            const T _sin(std::sin(half_angle));

            return complex::TQuaternion<T>(std::cos(half_angle), axis.x * _sin, axis.y * _sin, axis.z * _sin);
        }

        template<typename T>
        const matrix::TMatrix3x3<T> rotationMatrix3x3(const complex::TQuaternion<T> &q) noexcept {

#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_SUM(9)
            RM_STAT_SUB(6)
#endif

            const T x2(q.i + q.i);
            const T y2(q.j + q.j);
            const T z2(q.k + q.k);

            const T xx(q.i * x2);
            const T xy(q.i * y2);
            const T xz(q.i * z2);

            const T yy(q.j * y2);
            const T yz(q.j * z2);
            const T zz(q.k * z2);

            const T wx(q.w * x2);
            const T wy(q.w * y2);
            const T wz(q.w * z2);

            return matrix::TMatrix3x3<T>(
                    (T) 1 - (yy + zz),
                    xy - wz,
                    xz + wy,

                    xy + wz,
                    (T) 1 - (xx + zz),
                    yz - wx,

                    xz - wy,
                    yz + wx,
                    (T) 1 - (xx + yy)
            );
        }


        template<typename T>
        const matrix::TAffineMatrix4x4<T> affineTRSMatrix4x4(const vector::TVector3<T> &position,
                                                             const complex::TQuaternion<T> &rotation) {


#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_SUM(9)
            RM_STAT_SUB(6)
#endif

            const T x2(rotation.i + rotation.i);
            const T y2(rotation.j + rotation.j);
            const T z2(rotation.k + rotation.k);

            const T xx(rotation.i * x2);
            const T xy(rotation.i * y2);
            const T xz(rotation.i * z2);

            const T yy(rotation.j * y2);
            const T yz(rotation.j * z2);
            const T zz(rotation.k * z2);

            const T wx(rotation.w * x2);
            const T wy(rotation.w * y2);
            const T wz(rotation.w * z2);

            matrix::TAffineMatrix4x4<T> m(

                    (T) 1 - (yy + zz),
                    xy - wz,
                    xz + wy,

                    xy + wz,
                    (T) 1 - (xx + zz),
                    yz - wx,

                    xz - wy,
                    yz + wx,
                    (T) 1 - (xx + yy),

                    position.x,
                    position.y,
                    position.z
            );


#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_SUM(6)
#endif

            m.m30 *= m.m00;
            m.m30 += (m.m10 * position.y + m.m20 * position.z);

            m.m31 *= m.m11;
            m.m31 += (m.m01 * position.x + m.m21 * position.z);

            m.m32 *= m.m22;
            m.m32 += (m.m02 * position.x + m.m12 * position.y);

            return m;
        };


        template<typename T>
        const matrix::TAffineMatrix4x4<T> affineTRSMatrix4x4(const vector::TVector3<T> &position,
                                                             const complex::TQuaternion<T> &rotation,
                                                             const vector::TVector3<T> &scale) {

#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_SUM(9)
            RM_STAT_SUB(6)
#endif

            const T x2(rotation.i + rotation.i);
            const T y2(rotation.j + rotation.j);
            const T z2(rotation.k + rotation.k);

            const T xx(rotation.i * x2);
            const T xy(rotation.i * y2);
            const T xz(rotation.i * z2);

            const T yy(rotation.j * y2);
            const T yz(rotation.j * z2);
            const T zz(rotation.k * z2);

            const T wx(rotation.w * x2);
            const T wy(rotation.w * y2);
            const T wz(rotation.w * z2);

            matrix::TAffineMatrix4x4<T> m(

                    (T) 1 - (yy + zz),
                    xy - wz,
                    xz + wy,

                    xy + wz,
                    (T) 1 - (xx + zz),
                    yz - wx,

                    xz - wy,
                    yz + wx,
                    (T) 1 - (xx + yy),

                    position.x,
                    position.y,
                    position.z
            );

#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_SUM(6)
#endif

            m.m30 *= m.m00;
            m.m30 += (m.m10 * position.y + m.m20 * position.z);

            m.m31 *= m.m11;
            m.m31 += (m.m01 * position.x + m.m21 * position.z);

            m.m32 *= m.m22;
            m.m32 += (m.m02 * position.x + m.m12 * position.y);


#ifdef RM_MATH_STAT
            RM_STAT_MUL(12)
#endif

            m.m00 *= scale.x;
            m.m01 *= scale.y;
            m.m02 *= scale.z;
            m.m10 *= scale.x;
            m.m11 *= scale.y;
            m.m12 *= scale.z;
            m.m20 *= scale.x;
            m.m21 *= scale.y;
            m.m22 *= scale.z;
            m.m30 *= scale.x;
            m.m31 *= scale.y;
            m.m32 *= scale.z;

            return m;
        }


        // Inverse

        template<typename T>
        const matrix::TAffineMatrix4x4<T> inverseAffineTRSMatrix4x4(const vector::TVector3<T> &position,
                                                                    const complex::TQuaternion<T> &rotation) {

#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
        RM_STAT_SUM(9)
        RM_STAT_SUB(6)
#endif

            const T x2(rotation.i + rotation.i);
            const T y2(rotation.j + rotation.j);
            const T z2(rotation.k + rotation.k);

            const T xx(rotation.i * x2);
            const T xy(rotation.i * y2);
            const T xz(rotation.i * z2);

            const T yy(rotation.j * y2);
            const T yz(rotation.j * z2);
            const T zz(rotation.k * z2);

            const T wx(rotation.w * x2);
            const T wy(rotation.w * y2);
            const T wz(rotation.w * z2);

            matrix::TAffineMatrix4x4<T> m(

                    (T) 1 - (yy + zz),
                    xy + wz,
                    xz - wy,

                    xy - wz,
                    (T) 1 - (xx + zz),
                    yz + wx,

                    xz + wy,
                    yz - wx,
                    (T) 1 - (xx + yy),

                    -position.x,
                    -position.y,
                    -position.z
            );
            return m;
        };


        template<typename T>
        const matrix::TAffineMatrix4x4<T> inverseAffineTRSMatrix4x4(const vector::TVector3<T> &position,
                                                                    const complex::TQuaternion<T> &rotation,
                                                                    const vector::TVector3<T> &scale) noexcept {

#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_SUM(9)
            RM_STAT_SUB(6)
#endif

            const T x2(rotation.i + rotation.i);
            const T y2(rotation.j + rotation.j);
            const T z2(rotation.k + rotation.k);

            const T xx(rotation.i * x2);
            const T xy(rotation.i * y2);
            const T xz(rotation.i * z2);

            const T yy(rotation.j * y2);
            const T yz(rotation.j * z2);
            const T zz(rotation.k * z2);

            const T wx(rotation.w * x2);
            const T wy(rotation.w * y2);
            const T wz(rotation.w * z2);

            const T sx((T) 1 / scale.x);
            const T sy((T) 1 / scale.y);
            const T sz((T) 1 / scale.z);

#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_DIV(3)
#endif

            return matrix::TAffineMatrix4x4<T>(

                    sx - sx * (yy + zz),
                    sx * (xy + wz),
                    sx * (xz - wy),

                    sy * (xy - wz),
                    sy - sy * (xx + zz),
                    sy * (yz + wx),

                    sz * (xz + wy),
                    sz * (yz - wx),
                    sz - sz * (xx + yy),

                    -position.x,
                    -position.y,
                    -position.z
            );
        };


        template<typename T>
        void convertTRSTransform(const matrix::TAffineMatrix4x4<T> &t,
                                 vector::TVector3<T> *position,
                                 complex::TQuaternion<T> *rotation,
                                 vector::TVector3<T> *scale) noexcept {
#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_SUM(2)
            RM_STAT_SUB(3)
#endif

            const auto vx(t.m01 * t.m12 - t.m02 * t.m11);
            const auto vy(t.m02 * t.m10 - t.m00 * t.m12);
            const auto vz(t.m00 * t.m11 - t.m01 * t.m10);

            const auto det(t.m20*vx + t.m21*vy + t.m22*vz);  // sx*sy*sz -> det[rotationMatrix]

            if ( equal_to_one<T>(det) && equal<T>(vx, t.row[2].x) && equal<T>(vy, t.row[2].y)) {
#ifdef RM_MATH_STAT
                RM_STAT_MUL(12)
                RM_STAT_SQRT(1)
                RM_STAT_SUM(9)
                RM_STAT_DIV(1)
                RM_STAT_SUB(3)
#endif

                position->x = t.m00 * t.m30 + t.m01 * t.m31 + t.m02 * t.m32;
                position->y = t.m10 * t.m30 + t.m11 * t.m31 + t.m12 * t.m32;
                position->z = t.m20 * t.m30 + t.m21 * t.m31 + t.m22 * t.m32;

                scale->z = scale->y = scale->x = (T)1;

                const auto  tr = t.m00 + t.m11 + t.m22;

                if (tr > 0) {
                    auto S = std::sqrt(tr + (T)1) * 2; // S=4*qw
                    rotation->w = (T)0.25 * S;
                    rotation->i = (t.m21 - t.m12) / S;
                    rotation->j = (t.m02 - t.m20) / S;
                    rotation->k = (t.m10 - t.m01) / S;
                } else if ((t.m00 > t.m11) && (t.m00 > t.m22)) {
                    auto S = std::sqrt((T)1 + t.m00 - t.m11 - t.m22) * 2; // S=4*qx
                    rotation->w = (t.m21 - t.m12) / S;
                    rotation->i = (T) 0.25 * S;
                    rotation->j = (t.m01 + t.m10) / S;
                    rotation->k = (t.m02 + t.m20) / S;
                } else if (t.m11 > t.m22) {
                    auto S = std::sqrt((T)1 + t.m11 - t.m00 - t.m22) * 2; // S=4*qy
                    rotation->w = (t.m02 - t.m20) / S;
                    rotation->i = (t.m01 + t.m10) / S;
                    rotation->j = (T)0.25 * S;
                    rotation->k = (t.m12 + t.m21) / S;
                } else {
                    auto S = std::sqrt((T)1 + t.m22 - t.m00 - t.m11) * 2; // S=4*qz
                    rotation->w = (t.m10 - t.m01) / S;
                    rotation->i = (t.m02 + t.m20) / S;
                    rotation->j = (t.m12 + t.m21) / S;
                    rotation->k = (T)0.25 * S;
                }

            } else {

                const auto sysz_sx = vx/t.row[2].x;
                const auto sxsz_sy = vy/t.row[2].y;
                const auto sxsy_sz = vz/t.row[2].z;

                const auto sx2 = sxsz_sy*sxsy_sz;
                const auto sy2 = sysz_sx*sxsy_sz;
                const auto sz2 = sysz_sx*sxsz_sy;

                scale->x = std::sqrt(sx2);
                scale->y = std::sqrt(sy2);
                scale->z = std::sqrt(sz2);

                if (det < 0) {
                    scale->x = -scale->x;
                    scale->y = -scale->y;
                    scale->z = -scale->z;
                }

                const auto invsx = ((T)1)/scale->x;
                const auto invsy = ((T)1)/scale->y;
                const auto invsz = ((T)1)/scale->z;

                const T m00(invsx * t.m00);
                const T m01(invsy * t.m01);
                const T m02(invsz * t.m02);

                const T m10(invsx * t.m10);
                const T m11(invsy * t.m11);
                const T m12(invsz * t.m12);

                const T m20(invsx * t.m20);
                const T m21(invsy * t.m21);
                const T m22(invsz * t.m22);

                const T m30(invsx * t.m30);
                const T m31(invsy * t.m31);
                const T m32(invsz * t.m32);

                position->x = m00 * m30 + m01 * m31 + m02 * m32;
                position->y = m10 * m30 + m11 * m31 + m12 * m32;
                position->z = m20 * m30 + m21 * m31 + m22 * m32;


                const auto  tr = m00 + m11 + m22;

                if (tr > 0) {
                    auto S = std::sqrt(tr + (T)1) * 2; // S=4*qw
                    rotation->w = (T)0.25 * S;
                    rotation->i = (m21 - m12) / S;
                    rotation->j = (m02 - m20) / S;
                    rotation->k = (m10 - m01) / S;
                } else if ((m00 > m11) && (m00 > m22)) {
                    auto S = std::sqrt((T)1 + m00 - m11 - m22) * 2; // S=4*qx
                    rotation->w = (m21 - m12) / S;
                    rotation->i = (T) 0.25 * S;
                    rotation->j = (m01 + m10) / S;
                    rotation->k = (m02 + m20) / S;
                } else if (m11 > m22) {
                    auto S = std::sqrt((T)1 + m11 - m00 - m22) * 2; // S=4*qy
                    rotation->w = (m02 - m20) / S;
                    rotation->i = (m01 + m10) / S;
                    rotation->j = (T)0.25 * S;
                    rotation->k = (m12 + m21) / S;
                } else {
                    auto S = std::sqrt((T)1 + m22 - m00 - m11) * 2; // S=4*qz
                    rotation->w = (m10 - m01) / S;
                    rotation->i = (m02 + m20) / S;
                    rotation->j = (m12 + m21) / S;
                    rotation->k = (T)0.25 * S;
                }

            }
        }
    }
}



#endif //RMVECTORMATH_TQUATERNIONUTILS_HPP
