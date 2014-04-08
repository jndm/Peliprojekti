#ifndef TYKINKUULA_H
#define TYKINKUULA_H

#include "Tekstuurit.h"
#include <cmath>

const int FRAMES_IN_SPRITESHEET = 3;

class Pelihahmo;

class Tykinkuula{
public:
	Tykinkuula(Pelihahmo* ph, Tekstuurit* text, int _direction, int downOrUp, int _kaannossuunta);
	void move(float fts);
	void render(int camx, int camy);
	bool ifRdyToBeDestroyed();
	float getX(){ return x; }
	float getY(){ return y; }
	int getSade(){ return sade; }

private:
	Tekstuurit* tykinkuulaText;
	float nopeus, x, y;
	int sade;
	bool rdyToBeDestroyed;
	int frame;
	SDL_Rect gSpriteClips[FRAMES_IN_SPRITESHEET];
	int direction;
	Pelihahmo *pelihahmo;
	int suuntaX, suuntaY;
	int downOrUp;
	int kaannossuunta;
};
#endif