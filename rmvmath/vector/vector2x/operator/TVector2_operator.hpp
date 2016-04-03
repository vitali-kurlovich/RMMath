//
// Created by Vitali Kurlovich on 12/11/15.
//

#ifndef RMVECTORMATH_TVECTOR2_OPERATOR_HPP
#define RMVECTORMATH_TVECTOR2_OPERATOR_HPP


#include "../TVector2_def.hpp"


namespace rmmath {

    namespace vector {

        template<typename T>
        inline bool operator == (const TVector2<T> &a, const TVector2<T> &b) {
            return &a == &b || (a.x == b.x && a.y == b.y );
        }

        template<typename T>
        inline bool operator != (const TVector2<T> &a, const TVector2<T> &b) {
            return !(a == b) ;
        }
    }
}



#endif //RMVECTORMATH_TVECTOR2_OPERATOR_HPP
