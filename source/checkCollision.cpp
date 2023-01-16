#include "MovingObject.h"

bool checkCollision(MovingObject& obj_a, MovingObject& obj_b, vector <SDL_Rect>& obj_a_rec, vector <SDL_Rect>& obj_b_rec) {
	int upA{}, upB{};
	int rightA{}, rightB{};
	int downA{}, downB{};
	int leftA{}, leftB{};

	for (int j = 0; j < obj_a.size_(); j++) {
		for (int i = 0; i < obj_b.size_(); i++) {
			upA = obj_a.getObjRect(j).y;
			downA = obj_a.getObjRect(j).y + obj_a.getObjRect(j).h;
			leftA = obj_a.getObjRect(j).x;
			rightA = obj_a.getObjRect(j).x + obj_a.getObjRect(j).w;

			upB = obj_b.getObjRect(i).y;
			downB = obj_b.getObjRect(i).y + obj_b.getObjRect(i).h;
			leftB = obj_b.getObjRect(i).x;
			rightB = obj_b.getObjRect(i).x + obj_b.getObjRect(i).w;

			if (upA <= downB && upA >= upB) {
				if (leftA >= leftB && leftA <= rightB) {
					obj_b.destroyObject(i);
					obj_b_rec.erase(obj_b_rec.begin() + i);
					obj_a.destroyObject(j);
					obj_a_rec.erase(obj_a_rec.begin() + j);
					return true;
				}
			}
		}
	}
	return false;
}
