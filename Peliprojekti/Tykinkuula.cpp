#include "Tykinkuula.h"
#include "Pelihahmo.h"
#include "Vihollinen.h"

Tykinkuula::Tykinkuula(Pelihahmo* ph, Tekstuurit* text, int _direction, int _downOrUp, int _kaannossuunta){
	tykinkuulaText = text;
	nopeus = 200;
	rdyToBeDestroyed = false;
	pelihahmo = ph;
	direction =  _direction;
	kaannossuunta = _kaannossuunta;
	fromVihollinen = false;

	//-1 vasen tykki, 1 oikea
	downOrUp = _downOrUp;
	sade = 23; 
	/*keskipiste x : cx = x + cos omega(=360-arctan(leveys/korkeus)-suunta)*x
	// y : cy = y + sin omega(=360-arctan(leveys/korkeus)-suunta)*y*/

	x = pelihahmo->getX()+(pelihahmo->getWidth()/2)-sade/2;
	y = pelihahmo->getY()+(pelihahmo->getHeight()/2)-sade/2;

	//Kerrotaan miten spritesheet jaetaan
	for(int i=0; i<FRAMES_IN_SPRITESHEET; ++i){
		gSpriteClips[i].x = 7+i*30;
		gSpriteClips[i].y = 7;
		gSpriteClips[i].w = sade;
		gSpriteClips[i].h = sade;
	}
	frame = 0;
}

Tykinkuula::Tykinkuula(Vihollinen* vihu, Tekstuurit* text, int _direction, int _downOrUp, int _kaannossuunta){
	tykinkuulaText = text;
	nopeus = 200;
	rdyToBeDestroyed = false;
	vihollinen = vihu;
	direction =  _direction;
	kaannossuunta = _kaannossuunta;
	fromVihollinen = true;

	//-1 vasen tykki, 1 oikea
	downOrUp = _downOrUp;
	sade = 23; 
	/*keskipiste x : cx = x + cos omega(=360-arctan(leveys/korkeus)-suunta)*x
	// y : cy = y + sin omega(=360-arctan(leveys/korkeus)-suunta)*y*/

	x = vihollinen->getX()+(vihollinen->getWidth()/2)-sade/2;
	y = vihollinen->getY()+(vihollinen->getHeight()/2)-sade/2;

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
	if(fromVihollinen) {
		if(downOrUp == -1){
			x-=(200*cos((90+direction)*M_PI/180)-vihollinen->getXvelocity()*cos((direction)*M_PI/180))*fts;
			y-=(200*sin((90+direction)*M_PI/180)-vihollinen->getYvelocity()*sin((direction)*M_PI/180))*fts;
		}else if(downOrUp == 1){
			x+=(200*cos((90+direction)*M_PI/180)+vihollinen->getXvelocity()*cos(direction*M_PI/180))*fts;
			y+=(200*sin((90+direction)*M_PI/180)+vihollinen->getYvelocity()*sin(direction*M_PI/180))*fts;
		}
	} else {
		if(downOrUp == -1){
			x-=(200*cos((90+direction)*M_PI/180)-pelihahmo->getXvelocity()*cos((direction)*M_PI/180))*fts;
			y-=(200*sin((90+direction)*M_PI/180)-pelihahmo->getYvelocity()*sin((direction)*M_PI/180))*fts;
		}else if(downOrUp == 1){
			x+=(200*cos((90+direction)*M_PI/180)+pelihahmo->getXvelocity()*cos(direction*M_PI/180))*fts;
			y+=(200*sin((90+direction)*M_PI/180)+pelihahmo->getYvelocity()*sin(direction*M_PI/180))*fts;
		}
	}
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
