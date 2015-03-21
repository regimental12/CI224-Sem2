EXTRA_DIST = Cube.h Game.h ImageLoader.h Shader.h World.h Camera.h Chunk.h

bin_PROGRAMS = MineClone
MineClone_SOURCES = Cube.cpp main.cpp Game.cpp Shader.cpp ImageLoader.cpp World.cpp Camera.cpp Chunk.cpp

AM_CPPFLAGS = -DGL_GLEXT_PROTOTYPES -DGL3_PROTOTYPES
AM_CPPFLAGS += -std=c++11
AM_CPPFLAGS += $(gl_CFLAGS) $(glew_CFLAGS) $(sdl2_CFLAGS) $(sdl2_image_CFLAGS)
LIBS += $(gl_LIBS) $(glew_LIBS) $(sdl2_LIBS) $(sdl2_image_LIBS)