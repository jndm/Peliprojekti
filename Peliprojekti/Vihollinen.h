#ifndef VIHOLLINEN_H
#define VIHOLLINEN_H

#include "Tekstuurit.h"
#include "Tykinkuula.h"
#include "Pelihahmo.h"

//using namespace std;
class Maailma;

class Vihollinen{
private:
	Tekstuurit* healthBarText;
	Tekstuurit* vihollinenText;
	Tekstuurit* targetText;
	Tekstuurit* cannonballText;
	SDL_Rect gSpriteClips[2];
	vector<Tykinkuula*> cannonballs;
	Uint32 lastShootTime, shootingDelay;
	int hp;
	int width, height, turnDirection;
	float x, y, dy, dx, centerX, centerY, velocity, targetX, targetY, suunta;
	void calculateTarget(float pelaajaX, float pelaajaY);
	void fireCannonball(int cannon);
	int calculateTurnDirection();
	int merkki(float f);
	Pelihahmo* pelihahmo;
	Maailma* maailma;
	void setVelocity(float v);

public:
	void move(float fts);
	Vihollinen(float xp, float yp, float _suunta, Pelihahmo* _pelihahmo, Maailma *_maailma);
	float getX();
	float getY();
	float getXvelocity(){ return dx; }
	float getYvelocity(){ return dy; }
	int getWidth();
	int getHeight();
	int getHp();
	void render(int cx, int cy);
	vector<Tykinkuula*> *getCannonballs(){ return &cannonballs; }
	bool checkIfCannonballHit(Tykinkuula* tk);
	void lowerHp(int dmg);
	void setVihollinenText(Tekstuurit* tekst);
	void setTargetText(Tekstuurit* tekst);
	void setHealthBarText(Tekstuurit* tekst);
	void setCannonballText(Tekstuurit* tekst);
};

#endif