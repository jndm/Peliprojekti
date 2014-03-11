#include "Tykinkuula.h"
#include "Pelihahmo.h"

Tykinkuula::Tykinkuula(Pelihahmo* ph, Tekstuurit* text, int _direction){
	tykinkuulaText = text;
	nopeus = 200;
	rdyToBeDestroyed = false;
	pelihahmo = ph;
	direction =  0;

	//keskipiste x : cx = x + cos omega(=360-arctan(leveys/korkeus)-suunta)*x
	// y : cy = y + sin omega(=360-arctan(leveys/korkeus)-suunta)*y
	suuntaX = cos(360-atan2(pelihahmo->getWidth(), pelihahmo->getHeight())-direction);
	suuntaY = sin(360-atan2(pelihahmo->getWidth(), pelihahmo->getHeight())-direction);
	int keskipisteX = pelihahmo->getX() + suuntaX*pelihahmo->getWidth();
	int keskipisteY = pelihahmo->getY() + suuntaY*pelihahmo->getHeight();
	x = keskipisteX;
	y = keskipisteY;

	//Kerrotaan miten spritesheet jaetaan
	for(int i=0; i<FRAMES_IN_SPRITESHEET; ++i){
		gSpriteClips[i].x = 7+i*30;
		gSpriteClips[i].y = 7;
		gSpriteClips[i].w = 23;
		gSpriteClips[i].h = 23;
	}
	
	frame = 0;
}

void Tykinkuula::move(float fts){

	y+=50*fts*direction;
	x+=50*fts*direction;

}

void Tykinkuula::render(int camx, int camy){
    //Näytä neliö kameran suhteen
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
