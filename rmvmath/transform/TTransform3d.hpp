//
// Created by Vitali Kurlovich on 8/4/16.
//

#ifndef RMVECTORMATH_TTRANSFORM3D_HPP
#define RMVECTORMATH_TTRANSFORM3D_HPP

#include "TTransform.hpp"

#include "../matrix/TAffineMatrix4x4.hpp"
#include "../vector/TAffineVector4.hpp"
#include "../vector/TVector3.hpp"
#include "../complex/TQuaternion.hpp"


// TRS transformation

template<typename T>
class TTransform3d : public TTransform {

private:
    TQuaternion<T> _localRotation;
    TAffineVector4<T> _localPosition;
    TVector3<T> _localScale{1,1,1};

    TAffineMatrix4x4<T> _localTransform;

private:
    TAffineMatrix4x4<T> _globalTransform;

public:

    TTransform3d()
            : _localTransform(TAffineMatrix4x4<T>::identity()),
              _localPosition(TAffineVector4<T>::zero()),
              _localScale(1, 1, 1),
              _localRotation(TQuaternion<T>::identity())
    {
    }

    const TAffineMatrix4x4<T> getLocalTransform() {

        if (isTransformNeedsUpdate()) {

            setTransformUpdated();
        }
        return _localTransform;
    }



    const TAffineMatrix4x4<T> getGlobalTransform() {

        if (isGlobalTransformNeedsUpdate()) {

            setGlobalTransformUpdated();
        }
        return _globalTransform;
    }


};

#endif //RMVECTORMATH_TTRANSFORM3D_HPP
