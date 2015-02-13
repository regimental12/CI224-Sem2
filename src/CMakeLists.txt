#set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(Mine-Clone_SOURCES main.cpp game.cpp)

#might want to change above to
#file(GLOB Mine-Clone_SOURCES *.cpp)

add_executable(Mine-Clone ${Mine-Clone_SOURCES})