#pragma once
#include "MovingObject.h"
/*
Checks if two objects are colliding with each other. Functions based on position rectangels of objects, 
checks if first object's rectangle is colliding with second object's rectangle.
Return:
 true - if objects are colliding
 false - if objects are not colliding
Parameters:
 obj_a - MovingObject class object
 obj_b - MovingObject class object
 obj_a_rec - vector <SDL_Rect> which contains objects from MovingObject rectangles (from obj_a)
 obj_b_rec - vector <SDL_Rect> which contains objects from MovingObject rectangles (from obj_b)
*/
bool checkCollision(MovingObject& obj_a, MovingObject& obj_b, vector <SDL_Rect>& obj_a_rec, vector <SDL_Rect>& obj_b_rec);