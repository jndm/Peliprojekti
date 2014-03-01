#include "Pelihahmo.h"

Pelihahmo::Pelihahmo(void){
	x=100;
	y=100;
	dx = 0;
	dy = 0;
	width = 50;
	height = 50;
}

Pelihahmo::~Pelihahmo(void){

}
void Pelihahmo::move(float fts){
	x+=dx*fts;
	y+=dy*fts;

	//printf("x: %f y: %f liikeX: %f liikeY: %f\n",x,y,dx,dy);
}

float Pelihahmo::getX(){
	return x;
}

float Pelihahmo::getY(){
	return y;
}

int Pelihahmo::getWidth(){
	return width;
}

int Pelihahmo::getHeight(){
	return height;
}

void Pelihahmo::render(int camX, int camY )
{
    //Näytä neliö kameran suhteen
	pelihahmoText.render( (int)(x - camX), (int)(y - camY) );

}

//Tälle jotain fiksumpaa ratkaisua?
void Pelihahmo::setTekstuuri(Tekstuurit tekstuuri){
	pelihahmoText = tekstuuri;
}

void Pelihahmo::setXVelocity(float vx, int direction){
	dx = vx*direction;
}

void Pelihahmo::setYVelocity(float vy, int direction){
	dy = vy*direction;
	
}