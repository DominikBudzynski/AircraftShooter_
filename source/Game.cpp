#include "header.h"
#include "Game.h"

SDL_Window* Game::init(SDL_Window* win) {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Problems occured in init(): " << SDL_GetError() << endl;
	}
	else {
		if (!(IMG_Init(IMG_INIT_PNG) & 2)) {
			cout << "Problems occured in init(): " << IMG_GetError() << endl;
		}
		else {
			if ((win = SDL_CreateWindow("AircraftShooter.exe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCR_W, SCR_H, SDL_WINDOW_SHOWN)) == NULL) {
				cout << "Problems occured in init(): " << SDL_GetError() << endl;
			}
		}
	}
	return win;
}

SDL_Renderer* Game::createRend(SDL_Renderer* rend, SDL_Window* win) {

	bool flag{ true };

	if ((rend = SDL_CreateRenderer(win, -1, NULL)) == NULL) {
		cout << "Problems occured in createRend(): " << SDL_GetError() << endl;
		flag = false;
	}
	else {
		SDL_SetRenderDrawColor(rend, 255, 255, 255, 255);
	}
	return rend;
}

void Game::playerControl(Texture& player) {
	const Uint8* KeyPressed{ NULL };
	KeyPressed = SDL_GetKeyboardState(NULL);

	if (KeyPressed[SDL_SCANCODE_UP]) {
		player.control(UP, (1 / float(1000)));
	}
	else if (KeyPressed[SDL_SCANCODE_DOWN]) {
		player.control(DOWN, (1 / float(1000)));
	}
	else if (KeyPressed[SDL_SCANCODE_LEFT]) {
		player.control(LEFT, (1 / float(1000)));
	}
	else if (KeyPressed[SDL_SCANCODE_RIGHT]) {
		player.control(RIGHT, (1 / float(1000)));
	}
}

void Game::deinit(SDL_Window* win, SDL_Renderer* rend, SDL_Texture* tex, SDL_Texture* tex1, SDL_Texture* tex3) {
	SDL_DestroyTexture(tex);
	tex = NULL;
	SDL_DestroyTexture(tex1);
	tex1 = NULL;
	SDL_DestroyTexture(tex1);
	tex1 = NULL;
	SDL_DestroyRenderer(rend);
	SDL_DestroyWindow(win);

	IMG_Quit();
	SDL_Quit();
}