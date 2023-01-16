#include "Texture.h"

SDL_Texture* Texture::load(SDL_Renderer* rend, string path) {
	bool flag{ true };
	SDL_Surface* surf{ NULL };
	//path.c_str() used because of const char type of an argument of IMG_Load
	if ((surf = IMG_Load(path.c_str())) == NULL) {
		cout << "Problems occured in load(): " << SDL_GetError() << endl;
		flag = false;
	}
	else {
		//przezroczyste tlo tekstury
		SDL_SetColorKey(surf, SDL_TRUE, SDL_MapRGB(surf->format, 255, 255, 255));
		if ((tex = SDL_CreateTextureFromSurface(rend, surf)) == NULL) {
			cout << "Problems occured in load(): " << SDL_GetError() << endl;
			flag = false;
		}
	}
	surf = NULL;
	return tex;
}

SDL_Texture* Texture::getTex() {
	if (tex == NULL) {
		cout << "Error in getTex. There is no texture loaded" << endl;
	}
	else {
		return tex;
	}
}

Texture::Texture(int xpos, int ypos, int w, int h) {
	posSize.x = xpos;
	posSize.y = ypos;
	posSize.w = w;
	posSize.h = h;
	velocity = 0;
}

Texture::Texture() {
	posSize.x = 0;
	posSize.y = 0;
	posSize.w = 100;
	posSize.h = 100;
	velocity = 0;
}

int Texture::control(int dir, float frameTime) {

	if (dir == 3) {
		if (posSize.x <= SCR_W - posSize.w) {
			posSize.x += int(velocity * frameTime);
			return posSize.x;
		}
	}
	else if (dir == 2) {
		if (posSize.x >= 0) {
			posSize.x -= int(velocity * frameTime);
			return posSize.x;
		}
	}
	else if (dir == 0) {
		if (posSize.y >= 0) {
			posSize.y -= int(velocity * frameTime);
			return posSize.y;
		}
	}
	else if (dir == 1) {
		if (posSize.y <= (SCR_H - posSize.h)) {
			posSize.y += int(velocity * frameTime);
			return posSize.y;
		}
	}
}

SDL_Rect Texture::getRect() {
	return posSize;
}

void Texture::setVel(int vel) {
	if (vel < 0) {
		cout << "Error. Velocity can't be less than zero" << endl;
	}
	else {
		velocity = int(vel);
	}
}

void Texture::setId(int ID) {
	id = ID;
}