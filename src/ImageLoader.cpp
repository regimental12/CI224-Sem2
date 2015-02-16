#include "ImageLoader.h"

ImageLoader::ImageLoader()
{
    surface = nullptr;
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
    return texture;
}

