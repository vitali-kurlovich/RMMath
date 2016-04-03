//
// Created by Vitali Kurlovich on 1/20/16.
//

#ifndef RMVECTORMATH_TAFFINEVECTOR4_DEF_HPP
#define RMVECTORMATH_TAFFINEVECTOR4_DEF_HPP


namespace rmmath {

    namespace vector {

        /*
         * T x, y, z, 1;
         */

        template<typename T>
        struct TAffineVector4 {
            T x, y, z;
        };

    }
}

#endif //RMVECTORMATH_TAFFINEVECTOR4_DEF_HPP
