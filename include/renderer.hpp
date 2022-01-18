#ifndef RAYSTER_RENDERER_HPP
#define RAYSTER_RENDERER_HPP

#include <fstream>
#include <memory>
#include <string>

#include "framebuffer.hpp"
#include "geometry.hpp"
#include "shader.hpp"
#include "viewport.hpp"

namespace rayster {
    class renderer {
    public:
        renderer()
        {
            fb_ = std::make_unique<ppm_framebuffer>(1024, 1024);
            view_.min = {0, 0};
            view_.max = {1024, 1024};
            view_.near = 0;
            view_.far = 1;
        }

        void clear(color_rgba color) {
            fb_->clear(color);
        }

        const framebuffer& fb() const {
            return *fb_;
        }

        const viewport& view() const {
            return view_;
        }

        void draw_triangle(triangle tri, shader& s);
        
/*
        void draw_cube(const cube& c, shader& s) {
            for (auto& tri : c) {
                draw_triangle(tri, s);
            }
        }
 */
    private:
        std::unique_ptr<framebuffer> fb_;
        viewport view_;
    };
}

#endif