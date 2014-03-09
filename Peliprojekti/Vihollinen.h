#ifndef VIHOLLINEN_H
#define VIHOLLINEN_H

#include "Tekstuurit.h"
#include "Pelihahmo.h"
#include <complex>

//using namespace std;

class Vihollinen{
private:
	int width, height;
	float x, y, dy, dx, centerX, centerY, targetX, targetY, suunta;
	void calculateTarget();
	Pelihahmo* pelihahmo;
	void setXVelocity(float vx);
	void setYVelocity(float vy);

public:
	void move(float fts);
	Vihollinen(float xp, float yp, Pelihahmo* _pelihahmo, Tekstuurit text);
	float getX();
	float getY();
	int getWidth();
	int getHeight();

	void render(int cx, int cy);
	Tekstuurit vihollinenText;
};

#endif