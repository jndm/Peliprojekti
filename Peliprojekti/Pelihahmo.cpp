#include "Pelihahmo.h"

Pelihahmo::Pelihahmo(){
	x=100;
	y=100;
	dx = 0;
	dy = 0;
	width = 50;
	height = 50;
	lastShootTime = 0;
	shootingDelay = 1000;
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
	camX = _camX;
	camY = _camY;
    //Näytä neliö kameran suhteen
	pelihahmoText.render( (int)(x - camX), (int)(y - camY) );

}

//Tälle jotain fiksumpaa ratkaisua?
void Pelihahmo::setCharacterTexture(Tekstuurit tekstuuri){
	pelihahmoText = tekstuuri;
}

void Pelihahmo::setCannonballTexture(Tekstuurit tekstuuri){
	cannonballText = tekstuuri;
}

void Pelihahmo::setXVelocity(float vx, int direction){
	dx = vx*direction;
}

void Pelihahmo::setYVelocity(float vy, int direction){
	dy = vy*direction;	
}

void Pelihahmo::ammu(int my){

	if(SDL_GetTicks() > lastShootTime + shootingDelay){
		if((y-camY)+height/2 >= my)
			cannonballs.push_back(new Tykinkuula(x+width/2-8, y-16, &cannonballText, -1));
		else
			cannonballs.push_back(new Tykinkuula(x+width/2-8, y+height, &cannonballText, 1));
		lastShootTime = SDL_GetTicks();
	}
}
