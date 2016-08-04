//
// Created by Vitali Kurlovich on 8/4/16.
//

#ifndef RMVECTORMATH_TTRANSFORM_HPP
#define RMVECTORMATH_TTRANSFORM_HPP

#ifdef RM_MATH_STAT
#include <profiler/profiler.hpp>
#endif

class TTransform {

private:
    TTransform* _parent{nullptr};
    std::vector<TTransform*>  _childs;

private:
    struct {
        unsigned int rotationChanged:1;
        unsigned int positionChanged:1;
        unsigned int scaleChanged:1;
        unsigned int transformChanged:1;

        unsigned int globalTransformChanged:1;

    } _flags;

public:

    inline const TTransform* getParent() noexcept {
        return _parent;
    }

    inline const bool hasParent() noexcept {
        return _parent != nullptr;
    }

    inline const std::vector<TTransform*> getChilds() const noexcept {
        return _childs;
    }

protected:

    void notifyChildsAboutGlobalTransformNeedsUpdate() noexcept;

    void setGlobalTransformNeedsUpdate() noexcept {
        if (!_flags.globalTransformChanged) {
            _flags.globalTransformChanged = true;
            notifyChildsAboutGlobalTransformNeedsUpdate();
        }
    }

    inline bool isGlobalTransformNeedsUpdate() const noexcept {
        return _flags.globalTransformChanged;
    }

    inline void setTransformNeedsUpdate() noexcept {
        _flags.transformChanged = true;
        setGlobalTransformNeedsUpdate();
    }

    inline bool isTransformNeedsUpdate() const noexcept {
        return _flags.transformChanged;
    }

    inline void setRotationNeedsUpdate() noexcept {
        _flags.rotationChanged = true;
        setTransformNeedsUpdate();
    }

    inline void setRotationUpdated() noexcept {
        _flags.rotationChanged = false;
    }

    inline bool isRotationNeedsUpdate() const noexcept {
        return _flags.rotationChanged;
    }

    inline void setPositionNeedsUpdate() noexcept {
        _flags.positionChanged = true;
        setTransformNeedsUpdate();
    }

    inline void setPositionUpdated() noexcept {
        _flags.positionChanged = false;
    }

    inline bool isPositionNeedsUpdate() const noexcept {
        return _flags.positionChanged;
    }

    inline void setScaleNeedsUpdate() noexcept {
        _flags.scaleChanged = true;
        setTransformNeedsUpdate();
    }

    inline void setScaleUpdated() noexcept {
        _flags.scaleChanged = false;
    }

    inline bool isScaleNeedsUpdate() const noexcept {
        return _flags.scaleChanged;
    }

    inline void setTransformUpdated() noexcept {
        _flags.transformChanged = true;
        setRotationUpdated();
        setTransformUpdated();
        setScaleUpdated();
    }

    inline void setGlobalTransformUpdated() noexcept {
        _flags.globalTransformChanged = false;
    }
};


void TTransform::notifyChildsAboutGlobalTransformNeedsUpdate() noexcept {
    for(TTransform* child : getChilds()) {
        child->setGlobalTransformNeedsUpdate();
    }
}

#endif //RMVECTORMATH_TTRANSFORM_HPP
