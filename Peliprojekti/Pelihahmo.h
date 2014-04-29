#ifndef PELIHAHMO_H
#define PELIHAHMO_H

#include "Tekstuurit.h"
#include "Tykinkuula.h"
#include <vector>

class Kamera;
using namespace std;

class Pelihahmo{
private:
	int width, height,kamerax,kameray,locxmap,locymap;
	float x, y, dy, dx,suunta;
	Tekstuurit pelihahmoText, cannonballText;
	vector<Tykinkuula*> cannonballs;
	int camX;
	int camY;
	Uint32 lastShootTime, shootingDelay;
	bool kaantyminen;
	int merkki(float f);

public:
	void move(float fts);
	Pelihahmo();
	~Pelihahmo(void);
	float getX();
	float getY();
	int getWidth();
	int getHeight();
	void setKaantyminen(bool kaantyminen);
	void setXVelocity(float vx);
	void setYVelocity(float vy);
	int kaannossuunta();
	void setKohde(int mx, int my);
	void render( int camX, int camY );
	void setCharacterTexture(Tekstuurit tekstuuri);
	void setCannonballTexture(Tekstuurit tekstuuri);
	void ammu(int tykki);
	vector<Tykinkuula*> *getCannonballs(){ return &cannonballs; }
	float getXvelocity(){ return dx; }
	float getYvelocity(){ return dy; }
	bool checkIfInArea(int rx, int ry, int rwidth, int rheight);
	void setX(float _x);
	void setY(float _y);
};

#endif