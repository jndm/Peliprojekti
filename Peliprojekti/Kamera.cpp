#include "Kamera.h"

void Kamera::alusta(int SCREEN_WIDTH, int SCREEN_HEIGHT, Pelihahmo* ph){
	camera.x = 0;
	camera.y = 0;
	camera.w = SCREEN_WIDTH;
	camera.h = SCREEN_HEIGHT;
	pelihahmo = ph;
}
void Kamera::moveCamera(int SCREEN_WIDTH, int SCREEN_HEIGHT, int LEVEL_WIDTH, int LEVEL_HEIGHT){
	camera.x = (pelihahmo->getX()+pelihahmo->getWidth()/2) - SCREEN_WIDTH / 2;
	camera.y = (pelihahmo->getY()+pelihahmo->getHeight()/2) - SCREEN_HEIGHT / 2;
	//printf("cX %d, cY %d\n", camera.x, camera.y);
	//Kamera ei saa n‰ytt‰‰ reunojen yli
	if( camera.x < 0 ){camera.x = 0;}
	if( camera.y < 0 ){camera.y = 0;}
	if( camera.x > LEVEL_WIDTH - camera.w ){camera.x = LEVEL_WIDTH - camera.w;}
	if( camera.y > LEVEL_HEIGHT - camera.h ){camera.y = LEVEL_HEIGHT - camera.h;}
}

