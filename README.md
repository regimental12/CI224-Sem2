[![Build Status](https://travis-ci.org/regimental12/CI224-Sem2.svg?branch=master)](https://travis-ci.org/regimental12/CI224-Sem2)

#README

##Dependancies
This project uses a few libraries from the get go these are:-
- [SDL2](https://www.libsdl.org/download-2.0.php)
- [SDL2_Image](https://www.libsdl.org/projects/SDL_image/)
- [GLEW](http://glew.sourceforge.net/)
- [GLM](http://glm.g-truc.net/0.9.6/index.html)

##Build Instructions  

If you have autotools and it's dependencies installed you should only have to run the following 3 commands to build.
`autoreconf -i`
`./configure`
`make all`

For windows builds you need to use teh standard g++ command and link to the libraries as autotools isn't the easiest thing to install on windows.

###Run information

From the root directory of the repo run the following command

`./src/Mineclone`

or 

`./src/Mineclone.exe` for windows.

##Marking Scheme  
**The main aim:**  
*Implement fewer features fully, rather than all features badly.*  
  
This is our marking scheme copied from ProjectBrief.md which we can check off things taht we've achieved to plot our progress so far.
  
**Use of industry standard tools (any apply)**  
  - [x] Git - 5%  
  - [x] Continuous Integration - 5%  
  - [x] Build System - 5%  
  - [ ] Unit testing - 5%  
  
**Quality of code (any apply)**  
  - [x] Clean structure - 5%  
  - [x] Modularity of engine/codebase - 10%  
  - [x] Cross platform build - 10%  
  
**Working block world (only one applies)**  
  - [x] A basic block world (hard coded) - 5%  
  - [x] A procedural block world  - 10%  
  - [x] A block world with data structures (chunks) - 10%
  - [x] A procedural block world with proper data structure - 20%  
  
**Working player (only one applies)**  
  - [x] A player that moves - 5%  
  - [x] A player with HUD - 10%  
  - [x] A player with interaction - 15%  
  - [x] A player with interaction and HUD and inventory - 20%  
  
**Working entities (only one applies)**  
  - [x] Optimisations done - up to 20%
