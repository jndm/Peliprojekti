#ifndef KAMERA_H
#define KAMERA_H
#include "Pelihahmo.h"
#include <SDL.h>
#include <SDL_image.h>

class Kamera{
public:
	Pelihahmo* pelihahmo;
	void moveCamera(int SCREEN_WIDTH, int SCREEN_HEIGHT, int LEVEL_WIDTH, int LEVEL_HEIGHT);
	void alusta(int SCREEN_WIDTH, int SCREEN_HEIGHT, Pelihahmo* ph);
	SDL_Rect getCamera() { return camera; }
	int getCameraX(){return camera.x;}
	int getCameraY(){return camera.y;}

private:
	SDL_Rect camera;
};
#endif;