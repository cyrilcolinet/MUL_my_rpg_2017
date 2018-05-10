#!/bin/bash

## Clone CSFML repository
git clone https://github.com/SFML/CSFML.git

## Build library
mkdir -p CSFML/build
cd CSFML/build
cmake ..
