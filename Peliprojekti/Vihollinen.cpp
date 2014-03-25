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

bool Vihollinen::checkIfCannonballHit(Tykinkuula* tk){
	bool hit = true;

	printf("x: %f y: %f cX: %f cY: %f\n",x,y,tk->getX(),tk->getY());

	if(x+3 > tk->getX()+tk->getSade()-10){ hit = false; }
	else if( x + width -3 < tk->getX()){ hit = false; }
	else if( y > tk->getY()+tk->getSade()-10){ hit = false; }
    else if( y + height -3 < tk->getY()){ hit = false; }

	return hit;
}