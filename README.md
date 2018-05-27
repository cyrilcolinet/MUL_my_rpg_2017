# My RPG - It's your turn to create you final fantaisy

[![Build Status](https://travis-ci.com/mrlizzard/MUL_my_rpg_2017.svg?token=pg99qoFBnTMuMcLyfT5p&branch=master)](https://travis-ci.com/mrlizzard/MUL_my_rpg_2017)

- **Binary name:** my_rpg
- **Repository name:** my_rpg_2017
- **Repository rights:** ramassage-tek, clement.tinarelli@epitech.eu, lucas.marcel@epitech.eu
- **Language:** C
- **Group Size:** 3
- **Compilation:** via Makefile, including re, clean and fclean rules


# Subject

> :exclamation: Warning: This project is an Epitech project. Follow the golden rule ... do not make a project recovered on github or you can get -42! :tongue:

This project is one of the freest project of your first year. Create your own [RPG].
Your main challenge for this game will be to create a complete product using everything that you and your team know.

Your game must follow the following rules:
- The player needs to have characteristics which you can find in the status menu.
- The player can fight enemies, statistics will impact the fights results.
- There must be NPC in your game.
- You need to implement at least one quest.
- The player must have an inventory which can contain a limited set of items.
- The player can earn experience by winning fights and accomplishing specific actions.
- With enough experience, the player can level up, upgrading its statistics.

To give the users the feeling that you’re delivering a complete product you need to polish as much as possible your game.
- Having a pleasant user interface.
- Create a coherent universe (visual assets, audio assets, scenario, . . .)
- Create a funny game where the player has at least one goal.
- Create a game with a beginning and an end.

> :bulb: You should think and look for information about how to create a simple yet entertaining RPG.

## Requirements

### Mandatory
The following features are **mandatory** if your project is missing one of them it will not be evaluated further:
- The window can be closed using events.
- The game manage the input from the mouse click and keyboard.
- The game contain animated sprites rendered thanks to sprite sheets.
- Animations in your program are frame rate independent.
- Animations and movements in your program are timed by clocks.

### Must

The game **must** have:
- A starting menu with at least two buttons, one to launch a game, and one to quit the game.
- An escape key to pause the game when launched.
- A menu when the game is paused with at least two buttons, one to go to the starting menu and the other to leave the game.
- A basic fighting system.
- An inventory and status menu.
- A collision system so that the player can move logically in the world.
- A simple particle system that can display at least 2 types of particles.

### Should

- Your window **should** stick between 800x600 pixels and 1920x1080 pixels.
- The game **should** have an “How To play” menu, explaining how to play your game.
- The game **should** have NPC with whom the player can interact (fight, quest, discuss).
- As much information as possible about the game **should** be stored in a configuration file.
- The buttons in your game **should** have at least three visual states: idle, hover, and clicked.
- If your game has cut scenes or an animated intro (and it **should**) the player **should** be able to skip it.
- The game **should** have a beginning and an end.
- The game **should** have an advanced collision system to manage complex fighting.

### Could

The game cou**could**:
- let the player save and load its own save.
- let the user customize its character.
- have different types of enemies.
- have a skill tree, unlocking different abilities (active and passive).
- have a “settings” menu that could contain sound options and/or screen size options.
- have a particle engine.
- use scripting to describe entities.
- have a map editor.

### Would

- The program **would** be a real video game.

> :exclamation: The size of your repository (including the assets) must be as small as possible. Think about the format and the encoding of your resource files (sounds, musics, images, etc.).
> An average maximal size might be 15MB, all included. Any repository exceeding this limit might not evaluated at all.

<div align="center"><img src="https://vignette.wikia.nocookie.net/finalfantasy/images/b/bf/FFIV_Cell_Logo.png/revision/latest?cb=20100805044807" alt="" /></div>

## Authorized functions

- From the C library:
  - write, malloc, free, memset
  - rand, srand
  - (f)open, (f)read, (f)close
  - opendir, readdir, closedir, getline

- From the CSFML library:
  - All functions

- For the math library:
  - All functions

- Any libraries that let you
  - Bind script languages.
  - Parse file

> :exclamation: Any unspecified functions are de facto banned.

> :bulb: Damn! How can you have a random seed without using time??

# Table of content
<!-- TOC depthFrom:1 depthTo:6 withLinks:1 updateOnSave:1 orderedList:0 -->

- [My RPG - It's your turn to create you final fantaisy](#my-rpg-its-your-turn-to-create-you-final-fantaisy)
- [Subject](#subject)
	- [Requirements](#requirements)
		- [Mandatory](#mandatory)
		- [Must](#must)
		- [Should](#should)
		- [Could](#could)
		- [Would](#would)
	- [Authorized functions](#authorized-functions)
- [Table of content](#table-of-content)

<!-- /TOC -->

[RPG]: https://en.wikipedia.org/wiki/Role-playing_video_game
