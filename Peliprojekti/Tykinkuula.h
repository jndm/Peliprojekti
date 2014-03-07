#ifndef TYKINKUULA_H
#define TYKINKUULA_H

#include "Tekstuurit.h"

const int FRAMES_IN_SPRITESHEET = 3;

class Tykinkuula{
public:
	Tykinkuula(float _x, float _y, Tekstuurit text, int _direction);
	void move(float fts);
	void render(int camx, int camy);
	
	bool ifRdyToBeDestroyed();

private:
	Tekstuurit tykinkuulaText;
	float nopeus, x, y;
	float getX(){ return x; }
	float getY(){ return y; }
	bool rdyToBeDestroyed;
	int frame;
	SDL_Rect gSpriteClips[FRAMES_IN_SPRITESHEET];
	int direction;
};
#endif