#include "Pelihahmo.h"

Pelihahmo::Pelihahmo(){
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

void Pelihahmo::render(int _camX, int _camY )
{
    //N�yt� neli� kameran suhteen
	pelihahmoText.render( (int)(x - camX), (int)(y - camY) , NULL, 0);

}

//T�lle jotain fiksumpaa ratkaisua?
void Pelihahmo::setCharacterTexture(Tekstuurit tekstuuri){
	pelihahmoText = tekstuuri;
}

void Pelihahmo::setCannonballTexture(Tekstuurit tekstuuri){
	cannonballText = tekstuuri;
}

void Pelihahmo::setXVelocity(float vx, int direction){
	
	dx = vx;
	
}

void Pelihahmo::setYVelocity(float vy, int direction){
	dy = vy*direction;
	
void Pelihahmo::ammu(int my){

	//if(SDL_GetTicks() > lastShootTime + shootingDelay){
		if((y-camY)+height/2 >= my){
			cannonballs.push_back(new Tykinkuula(this, &cannonballText, -1, -1));
		}
		else
			cannonballs.push_back(new Tykinkuula(this, &cannonballText, 1, 1));
		lastShootTime = SDL_GetTicks();
	//}
}


