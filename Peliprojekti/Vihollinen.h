#ifndef VIHOLLINEN_H
#define VIHOLLINEN_H

#include "Tekstuurit.h"
#include "Tykinkuula.h"
class Vihollinen{
private:
	int width, height;
	float x, y, dy, dx;
	Tekstuurit* healthBarText;
	Tekstuurit* vihollinenText;
	SDL_Rect gSpriteClips[2];
	int hp;

public:
	void move(float fts);
	Vihollinen(float xp, float yp, Tekstuurit* text, Tekstuurit* healthbartext);
	float getX();
	float getY();
	int getWidth();
	int getHeight();
	int getHp();
	void setXVelocity(float vx, int direction);
	void setYVelocity(float vy, int direction);

	void render(int cx, int cy);
	bool checkIfCannonballHit(Tykinkuula* tk);
	void lowerHp(int dmg);
};

#endif