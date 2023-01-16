#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

using std::cout, std::endl, std::string, std::vector;

//constant value of screen width and height
const int SCR_W{ 1280 };
const int SCR_H{ 1024 };

//constant value of frames pe seconds
const int FPS{ 120 };

//max time that frame can last
const int frameLast{ 1000 / FPS };

//used for function resposible for movement
enum MotionList {
	UP,
	DOWN,
	LEFT,
	RIGHT
};