#include "MovingObject.h"


void MovingObject::createObject(int xpos, int ypos, int w, int h, int id, int vel) {
	if (id < 0) {
		cout << "ID can't be less than 0. Enemy doesn't created" << endl;
	}
	else {
		objects.push_back(Texture(xpos, ypos, w, h));
		objects[id].setVel(vel);
		objId = id;
	}
}

SDL_Rect MovingObject::getObjRect(int enemyCnt) {
	if (enemyCnt < 0 || enemyCnt >= objects.size())
		cout << "Error in getObjRect: wrong parameter passed" << endl;
	else
		return objects[enemyCnt].getRect();
}

int MovingObject::controlObject(int id, int frameTime, int dir) {
	if (dir == DOWN) {
		return objects[id].control(DOWN, (frameTime / float(1000)));
	}
	else if (dir == UP) {
		return objects[id].control(UP, (frameTime / float(1000)));
	}
}

int MovingObject::size_() {
	return objects.size();
}

int MovingObject::destroyObject(int id) {
	objectTex.~Texture();
	objects.erase(objects.begin() + id);
	return 0;
}