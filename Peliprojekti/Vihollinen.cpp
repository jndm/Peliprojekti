#include "Vihollinen.h"

Vihollinen::Vihollinen(float xp, float yp, Tekstuurit* text, Tekstuurit* healthbartext){
	x=xp;
	y=yp;
	dx = 0;
	dy = 0;
	width = 50;
	height = 50;
	hp = 5;
	vihollinenText = text;
	healthBarText = healthbartext;
	for(int i=0; i<2; ++i){
		gSpriteClips[i].x = i*52;
		gSpriteClips[i].y = 0;
		gSpriteClips[i].w = 52;
		gSpriteClips[i].h = 10;
	}
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

int Vihollinen::getHp(){
	return hp;
}

void Vihollinen::render(int cx, int cy)
{
    //Näytä neliö kameran suhteen
	healthBarText->render(x - cx -1, y - cy-20, &gSpriteClips[0]);	//52 pitkä kuva -> keskitetään miinustamalla 1 x suunnasta
	healthBarText->render(x - cx -1, y - cy-20, &gSpriteClips[1]);
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

	if(x > tk->getX()+tk->getSade()/2){ hit = false; }
	else if( x + width-tk->getSade()/2 < tk->getX()){ hit = false; }
	else if( y > tk->getY()+tk->getSade()/2){ hit = false; }
	else if( y + height - tk->getSade()/2 < tk->getY()){ hit = false; }

	return hit;
}

void Vihollinen::lowerHp(int dmg){
	hp = hp - dmg;
	gSpriteClips[1].w = (int)(52*(hp/5.0));
}