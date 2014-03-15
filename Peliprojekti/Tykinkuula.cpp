#include "Tykinkuula.h"
#include "Pelihahmo.h"

Tykinkuula::Tykinkuula(Pelihahmo* ph, Tekstuurit* text, int _direction, int _downOrUp){
	tykinkuulaText = text;
	nopeus = 200;
	rdyToBeDestroyed = false;
	pelihahmo = ph;
	direction =  _direction;

	//-1 vasen tykki, 1 oikea
	downOrUp = _downOrUp;
	sade = 23; 
	/*keskipiste x : cx = x + cos omega(=360-arctan(leveys/korkeus)-suunta)*x
	// y : cy = y + sin omega(=360-arctan(leveys/korkeus)-suunta)*y*/

	if(downOrUp == -1){
		x = pelihahmo->getX()+(pelihahmo->getWidth()/2)-sade/2;
		y = pelihahmo->getY()+(pelihahmo->getHeight()/2)-sade/2;
	}
	else{
		x = pelihahmo->getX()+(pelihahmo->getWidth()/2)-sade/2;
		y = pelihahmo->getY()+(pelihahmo->getHeight()/2)-sade/2;
	}

	//Kerrotaan miten spritesheet jaetaan
	for(int i=0; i<FRAMES_IN_SPRITESHEET; ++i){
		gSpriteClips[i].x = 7+i*30;
		gSpriteClips[i].y = 7;
		gSpriteClips[i].w = sade;
		gSpriteClips[i].h = sade;
	}
	
	frame = 0;
}

void Tykinkuula::move(float fts){
	if(downOrUp == -1){
		x-=200*fts*cos((90+direction)*M_PI/180);
		y-=200*fts*sin((90+direction)*M_PI/180);		
	}else if(downOrUp == 1){
		x+=200*fts*cos((90+direction)*M_PI/180);
		y+=200*fts*sin((90+direction)*M_PI/180);
	}
}

void Tykinkuula::render(int camx, int camy){
    //N�yt� neli� kameran suhteen
	tykinkuulaText->render( x - camx, y - camy , &gSpriteClips[frame/15]);
	frame++;
	if( frame / 15 >= FRAMES_IN_SPRITESHEET ){
		nopeus = 0;
		frame = 0;
		rdyToBeDestroyed = true;
	}
}

bool Tykinkuula::ifRdyToBeDestroyed(){
	return rdyToBeDestroyed;
}
