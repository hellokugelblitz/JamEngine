#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include <map>
#include <glad/glad.h>
#include "texture.hpp"
#include "shader.hpp"

struct ResourceManager
{
public:
    ResourceManager() { }
    ~ResourceManager() { }

    // resource storage
    static std::map<std::string, Shader>    shaders;
    static std::map<std::string, Texture> textures;
    static Shader     load_shader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name);
    static Shader&    get_shader(std::string name);
    static Texture  load_texture(const char *file, bool alpha, std::string name);
    static Texture& get_texture(std::string name);
    static void       clear();

private:
    static Shader    load_shader_from_file(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);
    static Texture load_texture_from_file(const char *file, bool alpha);
};

#endif
