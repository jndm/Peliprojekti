#ifndef VIHOLLINEN_H
#define VIHOLLINEN_H

#include "Tekstuurit.h"

class Vihollinen{
private:
	int width, height;
	float x, y, dy, dx;

public:
	void move(float fts);
	Vihollinen(float xp, float yp, Tekstuurit* text);
	float getX();
	float getY();
	int getWidth();
	int getHeight();
	void setXVelocity(float vx, int direction);
	void setYVelocity(float vy, int direction);

	void render(int cx, int cy);
	Tekstuurit* vihollinenText;
};

#endif