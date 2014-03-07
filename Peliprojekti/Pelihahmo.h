#ifndef PELIHAHMO_H
#define PELIHAHMO_H

#include "Tekstuurit.h"
#include "Kamera.h"

class Pelihahmo{
private:
	int width, height;
	float x, y, dy, dx, suunta;
	Kamera *kamera;

public:
	void move(float fts);
	void hiiri(int x , int y);
	Pelihahmo(void);
	~Pelihahmo(void);
	float getX();
	float getY();
	void setCamera(Kamera *camera);
	int getWidth();
	int getHeight();
	void setXVelocity(float vx, int direction);
	void setYVelocity(float vy, int direction);

	void render( int camX, int camY );
	Tekstuurit pelihahmoText;
	void setTekstuuri(Tekstuurit tekstuuri);
};

#endif