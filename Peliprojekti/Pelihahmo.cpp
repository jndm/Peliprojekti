#include "Pelihahmo.h"
#define _USE_MATH_DEFINES

Pelihahmo::Pelihahmo(void){
	x=320-25;
	y=240-25;
	dx = 0;
	dy = 0;
	width = 50;
	height = 50;
	suunta = 0;
}

Pelihahmo::~Pelihahmo(void){

}
void Pelihahmo::move(float fts){
	//x+=dx*fts;
	//y+=dy*fts;
	float vekx = cos(suunta);
	float veky = sin(suunta);
	//float position = ( (vekx-x)*(my-y) - (veky-y)*(mx-x) );

	suunta-=M_PI;
	x+=std::cos(suunta)*dx*0.001;
	y+=std::sin(suunta)*dx*0.001;
	//printf("x: %f y: %f liikeX: %f liikeY: %f\n",x,y,dx,dy);
}

void Pelihahmo::setCamera(Kamera *camera){
	*kamera=*camera;
}

void Pelihahmo::hiiri(int mx, int my){
	printf("cX %d, cY %d\n", mx, my);
	
	float vekx = cos(suunta);
	float veky = sin(suunta);
	float position = ( (vekx-x)*(my-y) - (veky-y)*(mx-x) );
	if(position<0){
		printf("oikealle");
	}
	else if ( position>0){
		printf("vasemmalle");
	}
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