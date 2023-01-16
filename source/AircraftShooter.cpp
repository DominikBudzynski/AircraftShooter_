#include "Game.h"
#include "Texture.h"
#include "MovingObject.h"
#include "checkCollision.h"
#include "Timer.h"
#include "randomMers.h"

SDL_Window* win{ NULL };
SDL_Renderer* rend{ NULL };

SDL_Event event{};

Game game{};

//background 
Texture background{};

//player
Texture player(530, 850, 220, 170);
SDL_Rect playerRec{};

//enemy
Texture enemyTex;
vector <SDL_Rect> enemy_rec{};

//bullet
Texture bulletTex;
vector <SDL_Rect> bullet_rec{};

//movingobjects
MovingObject enemies;
MovingObject bullets;

//timers
Timer texTimer{};
Timer FPSTimer{};
Timer bulletTimer{};

int main(int argc, char* argv[]) {
	//starting needed timers
	FPSTimer.timerStart();
	bulletTimer.timerStart();
	texTimer.timerStart();

	//setting player velocity
	player.setVel(9000);

	bool quit{ false };
	int frameTime{};
	int enemyCnt{ 0 };
	int bulletCnt{ 0 };
	int frameStart{};

	//initalize SDL and create window
	if ((win = game.init(win)) == NULL) {
		cout << "Error with init() in main" << endl;
	}
	else {
		//creating a renderer
		if (((rend = game.createRend(rend, win)) == NULL)) {
			cout << "Error with renderer in main" << endl;
		}
		else {
			player.load(rend, "../assets/player.png");
			background.load(rend, "../assets/background.png");
			enemyTex.load(rend, "../assets/enemy.png");
			bulletTex.load(rend, "../assets/bullet.png");

			//checking if textures have been loaded properly
			if (player.getTex() == NULL || background.getTex() == NULL || bulletTex.getTex() == NULL || enemyTex.getTex() == NULL) {
				cout << "Error in loading textures " << endl;
			}
			else {
				while (!quit) {
					frameStart = FPSTimer.getTime();

					//checking if QUIT button was pressed
					while (SDL_PollEvent(&event) == 1) {
						if (event.type == SDL_QUIT) {
							quit = true;
						}
					}
					//clear the renderer
					SDL_RenderClear(rend);
					
					//getting player position rectangle
					playerRec = player.getRect();
					
					//rendering background and player textures
					SDL_RenderCopy(rend, background.getTex(), NULL, NULL);
					SDL_RenderCopy(rend, player.getTex(), NULL, &playerRec);

					
					//player controlling
					game.playerControl(player);

					//creating enemies
					if ((texTimer.getTime() > randomMers(500, 2000)) && enemyCnt < 5) {
						enemies.createObject(int(randomMers(120, SCR_W - 120)), 0, 120, 120, enemyCnt, 1000);
						enemy_rec.push_back(enemies.getObjRect(enemyCnt));
						texTimer.timerStart();
						++enemyCnt;
					}

					//creating bullets
					if (bulletTimer.getTime() > 350) {
						bullets.createObject(player.getRect().x + 100, player.getRect().y - 10, 20, 20, bulletCnt, 1000);
						bullet_rec.push_back(bullets.getObjRect(bulletCnt));
						bulletTimer.timerStart();
						++bulletCnt;
					}

					//chcecking if bullet is over screen, getting bullets rectangles
					if (bulletCnt > 0) {
						for (int i = 0; i < bullet_rec.size(); i++) {
							bullets.controlObject(i, 5, UP);
							bullet_rec[i] = bullets.getObjRect(i);
							if (bullets.getObjRect(i).y <= 0) {
								bullets.destroyObject(i);
								bullet_rec.erase(bullet_rec.begin() + i);
								--bulletCnt;
							}
						}	
					}

					//chcecking if enemy is over screen, getting enemies rectangles
					if (enemyCnt > 0) {
						for (int i = 0; i < enemy_rec.size(); i++) {
							enemies.controlObject(i, 3, DOWN);
							enemy_rec[i] = enemies.getObjRect(i);
							if (enemies.getObjRect(i).y >= (SCR_H - 120)) {
								enemies.destroyObject(i);
								enemy_rec.erase(enemy_rec.begin() + i);
								--enemyCnt;
							}														
						}						
					}

					//checking collision bullets with enemies
					if (checkCollision(bullets, enemies, bullet_rec, enemy_rec)) {
						--enemyCnt;
						--bulletCnt;
					}

					//rendering bullets
					for (int j = 0; j < bullet_rec.size(); j++) {
						bullet_rec[j] = bullets.getObjRect(j);
						SDL_RenderCopy(rend, bulletTex.getTex(), NULL, &bullet_rec[j]);
					}

					//rendering enemies
					for (int j = 0; j < enemy_rec.size(); j++) {
						enemy_rec[j] = enemies.getObjRect(j);
						SDL_RenderCopy(rend, enemyTex.getTex(), NULL, &enemy_rec[j]);
					}

					//update screen
					SDL_RenderPresent(rend);

					//part of the code responsible for constant frame rate
					frameTime = SDL_GetTicks() - frameStart;

					if (frameLast > frameTime) {
						SDL_Delay(frameLast - frameTime);
					}
				}
			}
		}
	}
	game.deinit(win, rend, player.getTex(), background.getTex(), enemyTex.getTex());
	return 0;
}