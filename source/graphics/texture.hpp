#ifndef TEXTURE_H
#define TEXTURE_H

#include "../../vendor/glad/glad.h"

struct Texture 
{
public:
    unsigned int id;
    unsigned int width, height; // width and height of loaded image in pixels
    unsigned int internal_format; // format of texture object
    unsigned int image_format; // format of loaded image
    unsigned int wrap_s; // wrapping mode on S axis
    unsigned int wrap_t; // wrapping mode on T axis
    unsigned int filter_min; // filtering mode if texture pixels < screen pixels
    unsigned int filter_max; // filtering mode if texture pixels > screen pixels
    Texture();
    void generate(unsigned int width, unsigned int height, unsigned char* data);
    void bind() const;
};

#endif
