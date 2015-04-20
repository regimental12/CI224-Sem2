
#include "ImageLoader.h"

ImageLoader::ImageLoader()
{
    surface = nullptr;
    texture = 0;
    height = 0;
    width = 0;
}

ImageLoader::~ImageLoader()
{

}

int ImageLoader::getheight()
{
    return height;
}

int ImageLoader::getwidth()
{
    return width;
}

GLuint ImageLoader::LoadTexture(std::string filename)
{
    /**
     *	Load image and generate opengl texture
     */
   // std::cout << "enteer LoadTexture" << std::endl;
    surface = IMG_Load(filename.c_str());
    if(surface == nullptr)
    {
	std::cout << "Loading image failed :: " << IMG_GetError() << std::endl;
    }
    //std:: cout << "1" << std::endl;
    width = surface->w;
    height = surface->h;
    
    glGenTextures(1 , &texture);
    glBindTexture(GL_TEXTURE_2D , texture);
    /**
     *	Set texture parameters
     */
    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_S , GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_WRAP_T , GL_REPEAT);
    
    /**
     *	Set texture filtering
     */
    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MIN_FILTER , GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D , GL_TEXTURE_MAG_FILTER , GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D , 0 , GL_RGB , width, height, 0 , GL_RGB , GL_UNSIGNED_BYTE, surface->pixels);
    
    glGenerateMipmap(GL_TEXTURE_2D);
    SDL_FreeSurface(surface);
    glBindTexture(GL_TEXTURE_2D , 0);
    return texture;
}

