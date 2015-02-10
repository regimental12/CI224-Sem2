# CI224-Sem2 

#Overview
##Team:
- George Vicarey
- Richard Hankins

##Features we'd like to implement

- [ ] A cube world
- [ ] Procedurally generated terrain.
- [ ] Basic inventory system
- [ ] Entities with pathfinding
- [ ] GUI/HUD
- [ ] Terrain has some form of chunk system
- [ ] Add and Remove blocks
- [ ] Some form of networking
- [ ] First person camera
- [ ] Night and day cycle.
- [ ] Pretty shaders.
- [ ] Audio.
- [ ] Multi user git intergration.
- [ ] Continous intergration
- [ ] Auto build system.
- [ ] Multi-platform

#Project Pitch
For this project we will be endeavouring to make a basic minecraft clone. It will be procedurally generated and contain at least 3 different types of textured block. The above list is a list of all the features we'd like to implement, although this doesn't necessarily mean we actually will. The mechanics we're definitely aiming to have finished are a procedurally generated block world saved using a chunk type data structure, in game entities which will have a form of artificial intelligence which will allow them to use path finding to attack the player, and a playable player this means we want interaction with the environment including a basic inventory system and heads-up-display.
Our aim is to work on these three features until they are completely polished. We'd much rather have three working features that leave us with a playable game than implement every feature badly and have a game that's so bug ridden it needs an exterminator. 

#Project Plan
Building off of both our work from last semester we will compile a common codebase that implements a basic block world. 

#Proposed technology
- C++
- **Libraries we'll use:**
  - SDL2
  - SDL2_image
  - libNoise
- openGL
- Unit Testing
- Automated build tools.

#Marking Scheme
**Implement fewer features fully, rather than all features badly.**

- Use of indistry standard tools (any apply)
  - Git - 5%
  - Continuous Integration - 5%
  - Build System - 5%
  - Unit testing - 5%

- Quality of code (any apply)
  - Clean structure - 5%
  - Modularity of engine/codebase - 10%
  - Cross platform build - 10%

- Working block world (only one applies)
  - [ ] A basic block world (hard coded) - 5%
  - [ ] A procederal block world  - 10%
  - [ ] A procedural block world with proper data structure - 20%

- Working player (only one applies)
  - [ ] plaer that moves - 5%
  - [ ] player with gui - 10%
  - [ ] player with interaction - 15%
  - [ ] player with interaction and gui and inventory - 20%

- Working entities (only one applies)
  - Entities with Basic AI (Just wander aimlessly) - 10%
  - Entities with path finding and goals (can actively attack/find the palyer) - 20%

