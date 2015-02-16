#ifndef _IMAGELOADERH_
#define _IMAGELOADERH_

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "GL/glew.h"
#include "GL/gl.h"
#include <iostream>

class ImageLoader
{
public:
    ImageLoader();
    ~ImageLoader();
    GLuint LoadTexture(std::string filename);

    int getwidth();
    int getheight();

private:
    GLuint texture;
    SDL_Surface* surface;
    int width , height;
};

#endif
