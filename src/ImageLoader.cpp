#include "ImageLoader.h"

/**
 * Define static instance variable
 */
ImageLoader* ImageLoader::loader = NULL;

/**
 * Initialise variables
 */
ImageLoader::ImageLoader()
{
      surface = nullptr;
      texture = 0;
      height = 0;
      width = 0;
      LoadTextures();
}

ImageLoader::~ImageLoader()
{
      
}

/**
 * Public access method
 * If instance does not exist, crate it and return it, else just return it
 */
ImageLoader* ImageLoader::getInstance()
{
      if(loader == nullptr)
      {
	    loader = new ImageLoader();
      }
      return loader;
}

/**
 * Load all textures.
 */
void ImageLoader::LoadTextures()
{
      Dirt = LoadTexture("images/dirt.jpg");
      Stone = LoadTexture("images/stone.jpg");
      SkyBox = LoadTexture("images/skybox.jpg");
}

/**
 * Return texture type
 */
GLuint ImageLoader::GetTexture(GLuint type)
{
      switch(type)
      {
	    case 1:
		  return Dirt;
		  break;
	    case 2:
		  return Stone;
		  break;
	    case 3:
		  return SkyBox;
		  break;
	    default:
		  return Stone;
		  break;
      }
      
}

GLuint ImageLoader::LoadTexture(std::string filename)
{
      /**
       *	Load image and generate opengl texture
       */
      surface = IMG_Load(filename.c_str());
      if(surface == nullptr)
      {
	    std::cout << "Loading image failed :: " << IMG_GetError() << std::endl;
      }
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

