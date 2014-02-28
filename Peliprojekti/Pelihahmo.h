#ifndef PELIHAHMO_H
#define PELIHAHMO_H

#include "Tekstuurit.h"

class Pelihahmo{
private:
	int width, height;
	float x, y, dy, dx;

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

	void render( int camX, int camY );
	Tekstuurit nelio;
	void setTekstuuri(Tekstuurit tekstuuri);
};

#endif