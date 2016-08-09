//
// Created by Vitali Kurlovich on 8/5/16.
//

#ifndef RMVECTORMATH_TQUATERNIONUTILS_HPP
#define RMVECTORMATH_TQUATERNIONUTILS_HPP

#include "common/common.hpp"
#include "common/arithmetic.hpp"
#include "common/trigonometry.hpp"


#include "complex/quaternion/TQuaternion_def.hpp"
#include "matrix/matrix3x3/TMatrix3x3_def.hpp"
#include "matrix/affinematrix4x4/TAffineMatrix4x4_def.hpp"
#include "vector/vector3x/TVector3_def.hpp"


namespace rmmath {

    template<typename T>
    const complex::TQuaternion<T> rotationQuaternion(const T angle, const vector::TVector3<T> &axis) {

#ifdef RM_MATH_STAT
        RM_STAT_MUL(3)
#endif

        const T half_angle(angle*(T)0.5);
        const T _sin(math::sin<T>(half_angle));

        return complex::TQuaternion<T>(math::cos<T>(half_angle), axis.x*_sin, axis.y*_sin, axis.z*_sin);
    }

    template<typename T>
    const matrix::TMatrix3x3<T> rotationMatrix3x3(const complex::TQuaternion <T> &q) noexcept {

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

        return matrix::TMatrix3x3<T> (
                (T)1 - (yy + zz),
                xy - wz,
                xz + wy,

                xy + wz,
                (T)1 - (xx + zz),
                yz - wx,

                xz - wy,
                yz + wx,
                (T)1 - (xx + yy)
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

                    (T)1 - (yy + zz),
                    xy - wz,
                    xz + wy,

                    xy + wz,
                    (T)1 - (xx + zz),
                    yz - wx,

                    xz - wy,
                    yz + wx,
                    (T)1 - (xx + yy),

                    position.x,
                    position.y,
                    position.z
            );


#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_SUM(6)
#endif

            m.m30 *= m.m00;
            m.m30 += (m.m10*position.y + m.m20*position.z);

            m.m31 *= m.m11;
            m.m31 += (m.m01*position.x + m.m21*position.z);

            m.m32 *= m.m22;
            m.m32 += (m.m02*position.x + m.m12*position.y);

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

                    (T)1 - (yy + zz),
                    xy - wz,
                    xz + wy,

                    xy + wz,
                    (T)1 - (xx + zz),
                    yz - wx,

                    xz - wy,
                    yz + wx,
                    (T)1 - (xx + yy),

                    position.x,
                    position.y,
                    position.z
            );

#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_SUM(6)
#endif

            m.m30 *= m.m00;
            m.m30 += (m.m10*position.y + m.m20*position.z);

            m.m31 *= m.m11;
            m.m31 += (m.m01*position.x + m.m21*position.z);

            m.m32 *= m.m22;
            m.m32 += (m.m02*position.x + m.m12*position.y);


#ifdef RM_MATH_STAT
            RM_STAT_MUL(12)
#endif

            m.m00 *= scale.x; m.m01 *= scale.y; m.m02 *= scale.z;
            m.m10 *= scale.x; m.m11 *= scale.y; m.m12 *= scale.z;
            m.m20 *= scale.x; m.m21 *= scale.y; m.m22 *= scale.z;
            m.m30 *= scale.x; m.m31 *= scale.y; m.m32 *= scale.z;

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

                    (T)1 - (yy + zz),
                    xy + wz,
                    xz - wy,

                    xy - wz,
                    (T)1 - (xx + zz),
                    yz + wx,

                    xz + wy,
                    yz - wx,
                    (T)1 - (xx + yy),

                    -position.x,
                    -position.y,
                    -position.z
            );
            return m;
    };


    template<typename T>
    const matrix::TAffineMatrix4x4<T> inverseAffineTRSMatrix4x4(const vector::TVector3<T> &position,
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

            const T sx( (T)1/scale.x);
            const T sy( (T)1/scale.y);
            const T sz( (T)1/scale.z);

#ifdef RM_MATH_STAT
            RM_STAT_MUL(9)
            RM_STAT_DIV(3)
#endif

            return matrix::TAffineMatrix4x4<T>(

                    sx - sx*(yy + zz),
                    sx*(xy + wz),
                    sx*(xz - wy),

                    sy*(xy - wz),
                    sy - sy*(xx + zz),
                    sy*(yz + wx),

                    sz*(xz + wy),
                    sz*(yz - wx),
                    sz - sz*(xx + yy),

                    -position.x,
                    -position.y,
                    -position.z
            );
    };



    template <typename T>
    void convertTRSTransform(const matrix::TAffineMatrix4x4<T> &t,
                             vector::TVector3<T> *position,
                             complex::TQuaternion<T> *rotation,
                             vector::TVector3<T> *scale) {

        const T x0(t.m02*t.m11 - t.m01*t.m12);
        const T x1(t.m02*t.m21 - t.m01*t.m22);
        const T x2(t.m12*t.m21 - t.m11*t.m22);

        const T y0(t.m02*t.m10 - t.m00*t.m12);
        const T y1(t.m02*t.m20 - t.m00*t.m22);
        const T y2(t.m12*t.m20 - t.m10*t.m22);

        const T z0(t.m01*t.m10 - t.m00*t.m11);
        const T z1(t.m01*t.m20 - t.m00*t.m21);
        const T z2(t.m11*t.m20 - t.m10*t.m21);

        T mm(x0*t.m20 - y0*t.m21 + z0*t.m22);

        mm*=mm;

         T invsx = x0*x0 + x1*x1 + x2*x2;
         T invsy = y0*y0 + y1*y1 + y2*y2;
         T invsz = z0*z0 + z1*z1 + z2*z2;

        bool scaled = false;

        if (rmmath::equal_to_one<T>(mm)) {

            if (!rmmath::equal_to_one<T>(invsx)) {
                scaled = true;
                invsx = rmmath::math::sqrt<T>(invsx);
            }

            if (!rmmath::equal_to_one<T>(invsy)) {
                scaled = true;
                invsy = rmmath::math::sqrt<T>(invsy);
            }

            if (!rmmath::equal_to_one<T>(invsz)) {
                scaled = true;
                invsz = rmmath::math::sqrt<T>(invsz);
            }

        } else {
            mm = (T)1/mm;

             invsx = rmmath::math::sqrt<T>(invsx*mm);
             invsy = rmmath::math::sqrt<T>(invsy*mm);
             invsz = rmmath::math::sqrt<T>(invsz*mm);
            scaled = true;
        }

        if (scaled) {

            const T m00(invsx*t.m00);
            const T m01(invsy*t.m01);
            const T m02(invsz*t.m02);

            const T m10(invsx*t.m10);
            const T m11(invsy*t.m11);
            const T m12(invsz*t.m12);

            const T m20(invsx*t.m20);
            const T m21(invsy*t.m21);
            const T m22(invsz*t.m22);

            rotation->w = rmmath::math::sqrt<T>(1 + m00 + m11 + m22);
            const T invW = (T)0.5/(rotation->w);
            rotation->i = (m21 - m12)*invW;
            rotation->j = (m02 - m20)*invW;
            rotation->k = (m10 - m01)*invW;
            rotation->w *= (T)0.5;

            const T m30(invsx*t.m30);
            const T m31(invsy*t.m31);
            const T m32(invsz*t.m32);

            position->x = m00*m30 + m01*m31 + m02*m32;
            position->y = m10*m30 + m11*m31 + m12*m32;
            position->z = m20*m30 + m21*m31 + m22*m32;

            scale->x = (T) 1 / invsx;
            scale->y = (T) 1 / invsy;
            scale->z = (T) 1 / invsz;

        } else {

            rotation->w = rmmath::math::sqrt<T>(1 + t.m00 + t.m11 + t.m22);
            const T invW = (T)0.5/(rotation->w);
            rotation->i = (t.m21 - t.m12)*invW;
            rotation->j = (t.m02 - t.m20)*invW;
            rotation->k = (t.m10 - t.m01)*invW;
            rotation->w *= (T)0.5;

            position->x = t.m00*t.m30 + t.m01*t.m31 + t.m02*t.m32;
            position->y = t.m10*t.m30 + t.m11*t.m31 + t.m12*t.m32;
            position->z = t.m20*t.m30 + t.m21*t.m31 + t.m22*t.m32;

            scale->x = (T)1;
            scale->y = (T)1;
            scale->z = (T)1;

        }


    }


}




#endif //RMVECTORMATH_TQUATERNIONUTILS_HPP
