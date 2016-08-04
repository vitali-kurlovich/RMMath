//
// Created by Vitali Kurlovich on 8/4/16.
//

#ifndef RMVECTORMATH_TTRANSFORM_HPP
#define RMVECTORMATH_TTRANSFORM_HPP


class TTransform {

private:
    TTransform* _parent{nullptr};

    std::vector<TTransform*> _childs;

public:

    constexpr const TTransform* getParent() noexcept {
        return _parent;
    }

    constexpr const bool hasParent() noexcept {
        return _parent != nullptr;
    }

};


#endif //RMVECTORMATH_TTRANSFORM_HPP
