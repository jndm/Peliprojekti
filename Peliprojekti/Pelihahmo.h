#ifndef PELIHAHMO_H
#define PELIHAHMO_H

#include "Tekstuurit.h"

class Kamera;
class Pelihahmo{
private:
	int width, height,kamerax,kameray,locxmap,locymap;
	float x, y, dy, dx,suunta;


public:
	void move(float fts);
	Pelihahmo(void);
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
	Tekstuurit pelihahmoText;
	void setTekstuuri(Tekstuurit tekstuuri);
};

#endif