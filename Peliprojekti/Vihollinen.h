#ifndef VIHOLLINEN_H
#define VIHOLLINEN_H

#include "Tekstuurit.h"
#include "Tykinkuula.h"
#include "Pelihahmo.h"
#include <complex>

//using namespace std;
class Maailma;

class Vihollinen{
private:
	Tekstuurit* healthBarText;
	Tekstuurit* vihollinenText;
	Tekstuurit* targetText;
	SDL_Rect gSpriteClips[2];
	int hp;
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
	int getHp();
	void render(int cx, int cy);
	bool checkIfCannonballHit(Tykinkuula* tk);
	void lowerHp(int dmg);
	void setVihollinenText(Tekstuurit* tekst);
	void setTargetText(Tekstuurit* tekst);
	void setHealthBarText(Tekstuurit* tekst);

};

#endif