#pragma once
#include "Texture.h"

class Game {
public:
	/*
	Initializes SDL, SDL_Image, creates window and it's surface.
	Return:
	 Returns created SDL_Window win.
	Parametrers:
	 SDL_Window* win - window to which will be returned created window
	 SDL_Surface* surf - surface of this window
	*/
	SDL_Window* init(SDL_Window* win);

	/*
	Creates renderer and set it's default color to white.
	Return:
	 Returns created renderer;
	Parameters:
	 win - created earlier window
	 surf - surface od this window
	*/
	SDL_Renderer* createRend(SDL_Renderer* rend, SDL_Window* win);

	/*
	Method responsible for controlling player's movement.
	Movement is controlled with arrows.
	Parameters:
	 player - Texture object in which player is contained
	*/
	void playerControl(Texture& player);

	/*
	Deinitializes SDL, SDL_Image, destroys window and 3 passed textures.
	Parameters:
	 win - window
	 tex - texture to destroy
	 tex1 - texture to destroy
	 tex2 - texture to destroy
	*/
	void deinit(SDL_Window* win, SDL_Renderer* rend, SDL_Texture* tex, SDL_Texture* tex1, SDL_Texture* tex2);
	
};
