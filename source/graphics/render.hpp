#ifndef RENDER_H
#define RENDER_H 

#include "texture.hpp" 
#include "shader.hpp"

// This is our global point of access for accessing render functionality in app code
struct RenderManager {
public:
    RenderManager();
    ~RenderManager();
    
    void set_shader(Shader &shader);
    void clear_screen(float r, float g, float b, float a);
    void draw_sprite(Texture &texture, glm::vec2 position, glm::vec2 size, float rotate, glm::vec3 color);
private:
    Shader       shader; 
    unsigned int quadVAO;
    int render_init();
    void init_quad_render_data();
};

#endif 
