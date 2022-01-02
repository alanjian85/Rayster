#ifndef RAYSTER_VIEWPORT_HPP
#define RAYSTER_VIEWPORT_HPP

#include "aabb2.hpp"
#include "matrix4.hpp"
#include "vector2.hpp"

namespace rayster {
    struct viewport {
        vector2 min;
        vector2 max;
        double near;
        double far;
        
        matrix4 transform() const noexcept {
            auto u = (max.x - min.x) / 2;
            auto v = (max.y - min.y) / 2;
            auto w = (far - near) / 2;
            return {
                u, 0, 0, u + min.x,
                0, v, 0, v + min.y,
                0, 0, w, w + near,
                0, 0, 0, 1
            };
        }

        aabb2 bounding_box() const noexcept {
            return {
                min,
                {max.x - 1, max.y - 1}
            };
        }
    };
}

#endif