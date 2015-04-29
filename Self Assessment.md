#Project Self Assessment

##Change to Marking Criteria

We had a whole category for "working entities" which had a weighting of 20%. We scrapped this category and redistributed the weighting to a new category for optimising our engine. What follows is the up to date marking scheme.

**Use of industry standard tools (any apply)**  
  - Git - 5%  
  - Continuous Integration - 5%  
  - Build System - 5%  
  - Unit testing - 5%  
  
**Quality of code (any apply)**  
  - Clean structure - 5%  
  - Modularity of engine/codebase - 10%  
  - Cross platform build - 10%  
  
**Working block world (only one applies)**  
  - A basic block world (hard coded) - 5%  
  - A procedural block world  - 10%  
  - A procedural block world with proper data structure - 20%  
  
**Working player (only one applies)**  
  - A player that moves - 5%  
  - A player with HUD - 10%  
  - A player with interaction - 15%  
  - A player with interaction and HUD and inventory - 20%  
 
**Engine optimisations**
 - Optimised code including load times - up to 20%

##Justifications for marking

###Use of industry standard tools

We have used git from the very beginning of our project along with autotools as our build system and Travis CI for continuous integration this adds up to a 155 out of a possible 20% since we miss out on 5% with unit testing as we just dived right into coding without sitting back and writing a unit test first.

###Quality of code

We have kept a clean code structure throughout our game and have kept the modularity of the engine as open as we expected to with the ability to add extra cube types being a 30 second job at most. We did successfully get our game to run on Windows 8.1, Fedora 20 and Ubuntu 14.04 & 15.04. This shoudl give us 25% for this category.

###Working block world

Our block world is procedurally generated and uses two visible types of cube with an transparent air type as well. The world is separated into 16*48*16 block chunks which is the data structure we were hoping to achieve.  That totals 20% in this category.

###Working player

Our game features a moving player  that can interact with the world by destroying and placing blocks that it can collide with. There is also a working inventory system that is displayed in the windows title bar. This gives us 15-20% in this category.

###Engine optimisations

This is quite a broad category. We've optimised our game in the following ways. Rather than rendering every block in the world model we only render any block that is touching an Air block essentially only rendering blocks that have a visible face. We've also optimised our texture loading so that rather than every cube having it's own texture and texture loader the textures are loaded by the game, one for each cube type and then passed to the cubes to use when they need to render so every stone cube uses the same texture in memory, instead of having it's own one.

Given more time we could have optimised further by only having one model of each cube type in GPU memory and instancing that many times across the world. we also could have implemented some frustum culling so cubes outside the camera's view don't get rendered. We also realise that the raycasting can be refined a bit more. 

Taking this into consideration we feel 12-17% is a fair mark in this category.
