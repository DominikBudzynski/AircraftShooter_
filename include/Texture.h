#pragma once
#include "Header.h"

class Texture {
public:
	/*
	Creates the Texture class objects with default parameters.
	*/
	Texture();

	/*
	Creates the Texture class objects with specified parameters.
	*/
	Texture(int xpos, int ypos, int w, int h);
	/*
	Loads texture to the internal attribute.
	Sets the background of texture transparent if it's white.
	Return:
	 Returns SDL_Texture* texture.
	Parameterts:
	 rend - renderer to which texture will be passed
	 path - path to the texture 
	*/
	SDL_Texture* load(SDL_Renderer* rend, string path);

	/*
	Return:
	 Returns texture of the object.
	*/
	SDL_Texture* getTex();

	/*
	Return:
	 Returns position rectangle of the object.
	*/
	SDL_Rect getRect();

	/*
	Controls the movement of the texture.
	Return:
	 Returns x or y position of the object,
	 depending on which of these were changed.
	Parameters:
	 dir - direction in which object will be moving,
		   passed using MotionList defined in Header.h
	 frameTime - time of each frame 
	*/
	int control(int dir, float frameTime);

	/*
	Sets velocity of the object.
	*/
	void setVel(int vel);

	/*
	Sets ID of the object.
	*/
	void setId(int ID);

private:
	SDL_Texture* tex;
	SDL_Rect posSize;
	float velocity;
	int id;
};