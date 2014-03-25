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
	float x, y, dy, dx, centerX, centerY, velocity, targetX, targetY, suunta;
	void calculateTarget(float pelaajaX, float pelaajaY);
	int calculateTurnDirection();
	int merkki(float f);
	Pelihahmo* pelihahmo;
	Maailma *maailma;
	void setVelocity(float v);

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