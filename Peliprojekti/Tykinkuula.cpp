#include "Tykinkuula.h"

Tykinkuula::Tykinkuula(float _x, float _y, Tekstuurit text, int _direction){
	x = _x;
	y = _y;
	tykinkuulaText = text;
	nopeus = 200;
	rdyToBeDestroyed = false;

	//Kerrotaan miten spritesheet jaetaan
	for(int i=0; i<FRAMES_IN_SPRITESHEET; ++i){
		gSpriteClips[i].x = 7+i*30;
		gSpriteClips[i].y = 7;
		gSpriteClips[i].w = 23;
		gSpriteClips[i].h = 23;
	}
	direction = _direction;
	frame = 0;
}

void Tykinkuula::move(float fts){
	y+=nopeus*fts*direction;
}

void Tykinkuula::render(int camx, int camy){
    //Näytä neliö kameran suhteen
	tykinkuulaText.render( x - camx, y - camy , &gSpriteClips[frame/15]);
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