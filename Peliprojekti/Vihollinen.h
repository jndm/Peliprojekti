#ifndef VIHOLLINEN_H
#define VIHOLLINEN_H

#include "Tekstuurit.h"
#include "Pelihahmo.h"
#include <complex>

//using namespace std;
class Maailma;

class Vihollinen{
private:
	int width, height, turnDirection;
	float x, y, dy, dx, centerX, centerY, targetX, targetY, suunta;
	void calculateTarget();
	void calculateTurnDirection();
	Pelihahmo* pelihahmo;
	Maailma *maailma;
	void setXVelocity(float vx);
	void setYVelocity(float vy);

public:
	void move(float fts);
	Vihollinen(float xp, float yp, float _suunta, Pelihahmo* _pelihahmo, Maailma *_maailma);
	float getX();
	float getY();
	int getWidth();
	int getHeight();

	void render(int cx, int cy);
	Tekstuurit vihollinenText;
};

#endif