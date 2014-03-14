#include "Tykinkuula.h"
#include "Pelihahmo.h"

Tykinkuula::Tykinkuula(Pelihahmo* ph, Tekstuurit* text, int _direction, int _downOrUp){
	tykinkuulaText = text;
	nopeus = 200;
	rdyToBeDestroyed = false;
	pelihahmo = ph;
	direction =  -90;
	downOrUp = _downOrUp;
	sade = 23; 
	/*keskipiste x : cx = x + cos omega(=360-arctan(leveys/korkeus)-suunta)*x
	// y : cy = y + sin omega(=360-arctan(leveys/korkeus)-suunta)*y
	x = pelihahmo->getX()+(pelihahmo->getWidth()/2)*cos(direction*M_PI/180);
	y = pelihahmo->getY()+(pelihahmo->getHeight()/2)*sin(direction*M_PI/180);*/

	x = pelihahmo->getX()+(pelihahmo->getWidth()/2)-sade/2;
	y = pelihahmo->getY()+(pelihahmo->getHeight()/2)-sade/2;
	printf("x: %f\n",(pelihahmo->getWidth()/2)*cos(direction*M_PI/180));
	printf("y: %f\n",(pelihahmo->getHeight()/2)*sin(direction*M_PI/180));

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
	if(downOrUp == -1 && direction>-180 && direction<-90){
		y+=200*fts*sin((90-direction)*M_PI/180);
		x+=200*fts*cos((90-direction)*M_PI/180);
	}else if(downOrUp == -1 && direction<0 && direction>-90){
		y+=200*fts*sin((90+direction)*M_PI/180);
		x+=200*fts*cos((90+direction)*M_PI/180);
	}else if(downOrUp == 1 && direction>0 && direction<90){
		y+=200*fts*sin((90+direction)*M_PI/180);
		x+=200*fts*cos((90+direction)*M_PI/180);
	}
	else if(downOrUp == 1 && direction>90 && direction<180){
		y+=200*fts*sin((90+direction)*M_PI/180);
		x+=200*fts*cos((90+direction)*M_PI/180);
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
