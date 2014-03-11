#include "Vihollinen.h"

Vihollinen::Vihollinen(float xp, float yp, Tekstuurit* text){
	x=xp;
	y=yp;
	dx = 0;
	dy = 0;
	width = 50;
	height = 50;
	vihollinenText = text;
}

void Vihollinen::move(float fts){
	x+=dx*fts;
	y+=dy*fts;

	//printf("x: %f y: %f liikeX: %f liikeY: %f\n",x,y,dx,dy);
}

float Vihollinen::getX(){
	return x;
}

float Vihollinen::getY(){
	return y;
}

int Vihollinen::getWidth(){
	return width;
}

int Vihollinen::getHeight(){
	return height;
}

void Vihollinen::render(int cx, int cy)
{
    //Näytä neliö kameran suhteen
	vihollinenText->render( x - cx, y - cy );

}

void Vihollinen::setXVelocity(float vx, int direction){
	dx = vx*direction;
}

void Vihollinen::setYVelocity(float vy, int direction){
	dy = vy*direction;
}