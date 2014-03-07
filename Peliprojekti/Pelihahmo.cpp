#include "Pelihahmo.h"

Pelihahmo::Pelihahmo(void){
	x=100;
	y=100;
	dx = 0;
	dy = 0;
	width = 50;
	height = 50;
	suunta=0;
}

Pelihahmo::~Pelihahmo(void){

}


void Pelihahmo::move(float fts){
	x+=dx*fts;
	y+=dy*fts;
	float suuntax=cos(suunta);
	float suuntay=sin(suunta);
	//float position = ( (Bx-Ax)*(Y-Ay) - (By-Ay)*(X-Ax) );
	//printf("x: %f y: %f liikeX: %f liikeY: %f\n",x,y,dx,dy);
}

void Pelihahmo::kaannossuunta(int mx,int my){



	
	locxmap=mx+kamerax;
	int locymap=my-kameray;
	int deltax=locxmap-x;
	int deltay=locymap-y;
	float angleInDegrees = atan2(deltay, deltax) * 180 / M_PI;
	printf("%f\n",angleInDegrees);
	//float position = ( (Bx-Ax)*(Y-Ay) - (By-Ay)*(X-Ax) );

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
	kamerax=camX;
	kameray=camY;
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