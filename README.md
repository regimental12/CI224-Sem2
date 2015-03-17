#README

##Dependancies
This project uses a few libraries from the get go these are:-
- [SDL2](https://www.libsdl.org/download-2.0.php)
- [GLEW](http://glew.sourceforge.net/)

##Build Instructions  
Currently to build you must run  the gcc command to compile all of src/* into an .exe file. When we implement a Build system the project will be built using `./configure` then `make all`

##Marking Scheme  
**The main aim:**  
*Implement fewer features fully, rather than all features badly.*  
  
This marking scheme is divided into categories some of which have multiple criteria. some categories allow for multiple selections, i.e. whichever ones apply can count to final total, other categories are on a *one* only basis i.e. pick the highest marked item which applies.  
  
**Use of industry standard tools (any apply)**  
  - [x] Git - 5%  
  - [x] Continuous Integration - 5%  
  - [x] Build System - 5%  
  - [ ] Unit testing - 5%  
  
**Quality of code (any apply)**  
  - [x] Clean structure - 5%  
  - [x] Modularity of engine/codebase - 10%  
  - [ ] Cross platform build - 10%  
  
**Working block world (only one applies)**  
  - [x] A basic block world (hard coded) - 5%  
  - [ ] A procedural block world  - 10%  
  - [ ] A procedural block world with proper data structure - 20%  
  
**Working player (only one applies)**  
  - [ ] A player that moves - 5%  
  - [ ] A player with HUD - 10%  
  - [ ] A player with interaction - 15%  
  - [ ] A player with interaction and HUD and inventory - 20%  
  
**Working entities (only one applies)**  
  - [ ] Entities with basic AI (Just wander aimlessly) - 10%  
  - [ ] Entities with path finding and goals (can actively attack/find the player) - 20%  
