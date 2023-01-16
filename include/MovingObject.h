#pragma once
#include "Texture.h"

class MovingObject {
public:
	/*
	Use vectorn_name.push_back() to assign each element to a vector.
	Return: 
	 Returns each enemy's rectangle. 
	Parameters:
	 enemyCnt - amount of objects to obtain their's rectangles
	*/
	SDL_Rect getObjRect(int enemyCnt);

	/*
	Creates objects and push it to the container.
	Parameters:
	 xpos - x position at which object have to be rendered
	 ypos - y position at which object have to be rendered
	 w - width of the object
	 h - height of the object
	 id - id of the object
	 vel - velocity of the objects
	*/
	void createObject(int xpos, int ypos, int w, int h, int id, int vel);

	/*
	Contorls the object's movement.
	Return:
	 Returns x or y position of the object,
	 depending on which of these were changed.
	Parameters:
	 id - id of the object which will be controlled
	 frameTime - time of each frame 
	 dir - direction in which object will be moving,
		   passed using MotionList defined in Header.h
	*/
	int controlObject(int id, int frameTime, int dir);

	/*
	Remove object from class's internal container.
	Parameters:
	 id - id of the object which will be removed
	*/
	int destroyObject(int id);

	/*
	Return:
	 Returns size of class's internal container with objects.
	*/
	int size_();

private:
	Texture objectTex;
	vector <SDL_Rect> objRects;
	vector <Texture> objects;
	int objId;
};