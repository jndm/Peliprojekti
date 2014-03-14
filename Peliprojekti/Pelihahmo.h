#ifndef PELIHAHMO_H
#define PELIHAHMO_H

#include "Tekstuurit.h"
#include "Tykinkuula.h"
#include <vector>

class Pelihahmo{
private:
	int width, height;
	float x, y, dy, dx;

public:
	void move(float fts);
	Pelihahmo();
	~Pelihahmo(void);
	float getX();
	float getY();
	int getWidth();
	int getHeight();
	void setXVelocity(float vx, int direction);
	void setYVelocity(float vy, int direction);
	int kaannossuunta();
	void setKohde(int mx, int my);
	void render( int camX, int camY );
	void setCharacterTexture(Tekstuurit tekstuuri);
	void setCannonballTexture(Tekstuurit tekstuuri);
	void ammu(int my);
	vector<Tykinkuula*> *getCannonballs(){ return &cannonballs; }
};

#endif