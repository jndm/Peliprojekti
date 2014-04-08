#include "Vihollinen.h"
#include "Pelihahmo.h"
#include "Maailma.h"
#include <math.h>

const float AMPUMISETAISYYS = 200; 

Vihollinen::Vihollinen(float xp, float yp, float _suunta, Pelihahmo* _pelihahmo, Maailma *_maailma) {
	x=xp;
	y=yp;
	dx = 1;
	dy = 1;
	targetX = 0;
	targetY = 0;
	width = 50;
	height = 50;
	centerX = x + width/2;
	centerY = y + height/2;
	velocity = 0.f;
	//vihollinenText = text;
	maailma = _maailma;
	pelihahmo = _pelihahmo;
	suunta = _suunta;
	turnDirection = 0.f;
	double roots[4];
	hp = 5;
	for(int i=0; i<2; ++i){
		gSpriteClips[i].x = i*52;
		gSpriteClips[i].y = 0;
		gSpriteClips[i].w = 52;
		gSpriteClips[i].h = 10;
	}
}

void Vihollinen::setVihollinenText(Tekstuurit* tekst) {
	vihollinenText = tekst;
}

void Vihollinen::setTargetText(Tekstuurit* tekst) {
	targetText = tekst;
}

void Vihollinen::setHealthBarText(Tekstuurit* tekst) {
	healthBarText = tekst;
}

void Vihollinen::move(float fts) {
	float pelaajaX = pelihahmo->getX() + pelihahmo->getWidth()/2;
	float pelaajaY = pelihahmo->getY() + pelihahmo->getHeight()/2;
	float etaisyys2 = pow(pelaajaX - centerX, 2) + pow(pelaajaY - centerY, 2);
	if (etaisyys2 < 90000) {
		calculateTarget(pelaajaX, pelaajaY);
		velocity += 2;
		if( velocity > 150) {
			velocity = 150;
		}
	} else {
		velocity -= 2;
		if( velocity < 0) {
			velocity = 0;
		}
	}

	turnDirection = calculateTurnDirection();

	suunta += turnDirection * M_PI/180;
	if(suunta < -M_PI) {
		suunta = 2 * M_PI + suunta;
	}
	suunta = fmod(suunta + M_PI, 2 * M_PI) - M_PI;

	dx = velocity*cos(suunta);
	dy = velocity*sin(suunta);
	x+=dx*fts;
	y+=dy*fts;
	centerX = x + width/2;
	centerY = y + height/2;
	//printf("x: %f y: %f liikeX: %f liikeY: %f\n",x,y,dx,dy);
}

void Vihollinen::calculateTarget(float pelaajaX, float pelaajaY) {
	float angle = atan2(pelaajaY - centerY, pelaajaX - centerX);			// suunta radiaaneissa, jossa pelaaja on
	//(a, b) = pelaajan koordinantit
	//(c, d) = omat koordinantit
	//sin f = ampumisetäisyys / etäisyyspelaajasta
	//tan f = (ampumisetäisyys)/(etäisyyspelaajasta * cos f)
	//x^2 - 2ax + a^2 + y^2 - 2by + b^2 - (tan f)^2 * ((x - c)^2 + (y - d)^2) = 0
	float pisteetX[2];
	float pisteetY[2];

	if(angle < 0) {
		pisteetX[0] = pelaajaX + cos((M_PI + angle) - M_PI/4.) * AMPUMISETAISYYS;
		pisteetY[0] = pelaajaY + sin((M_PI + angle) - M_PI/4.) * AMPUMISETAISYYS;
		pisteetX[1] = pelaajaX + cos((M_PI + angle) + M_PI/4.) * AMPUMISETAISYYS;
		pisteetY[1] = pelaajaY + sin((M_PI + angle) + M_PI/4.) * AMPUMISETAISYYS;
	} else {
		pisteetX[0] = pelaajaX + cos((angle - M_PI) - M_PI/4.) * AMPUMISETAISYYS;
		pisteetY[0] = pelaajaY + sin((angle - M_PI) - M_PI/4.) * AMPUMISETAISYYS;
		pisteetX[1] = pelaajaX + cos((angle - M_PI) + M_PI/4.) * AMPUMISETAISYYS;
		pisteetY[1] = pelaajaY + sin((angle - M_PI) + M_PI/4.) * AMPUMISETAISYYS;
	}
	float kulma0 = fabs(atan2(pisteetY[0] - centerY, pisteetX[0] - centerX) - suunta);
	float kulma1 = fabs(atan2(pisteetY[1] - centerY, pisteetX[1] - centerX) - suunta);
	//printf("kulma0: %f, kulma1: %f\n", kulma0*180/M_PI, kulma1*180/M_PI);
	if(kulma0 >= M_PI) {
		kulma0 = 2*M_PI - kulma0;
	}
	if(kulma1 >= M_PI) {
		kulma1 = 2*M_PI - kulma1;
	}
	if(kulma0 < kulma1) {
		targetX = pisteetX[0];
		targetY = pisteetY[0];
	} else {
		targetX = pisteetX[1];
		targetY = pisteetY[1];
	}
	//targetX = pelaajaX + cos(angle-45) * AMPUMISETAISYYS;
	//targetY = pelaajaY + sin(angle-45) * AMPUMISETAISYYS;
	//dx = 150*cos(atan2(targetY - centerY, targetX - centerX));
	//dy = 150*sin(atan2(targetY - centerY, targetX - centerX));
}

int Vihollinen::calculateTurnDirection() {
	float kulma = atan2(targetY - centerY, targetX - centerX);
	kulma = (kulma + M_PI) - (suunta + M_PI);
	if(fabs(kulma) > M_PI) {
		kulma = kulma - merkki(kulma)*2*M_PI;
	}
	if(kulma < -M_PI/180) {
		return -1;
	} else if(kulma > M_PI/180) {
		return 1;
	} else {
		return 0;
	}
}

float Vihollinen::getX() {
	return x;
}

float Vihollinen::getY() {
	return y;
}

int Vihollinen::getWidth() {
	return width;
}

int Vihollinen::getHeight() {
	return height;
}

void Vihollinen::render(int cx, int cy) {
	maailma->getEnemyTexture()->render( x - cx, y - cy );	//Näytä neliö kameran suhteen
	maailma->getTargetTexture()->render( targetX - cx, targetY - cy);

	healthBarText->render(x - cx -1, y - cy-20, &gSpriteClips[0]);	//52 pitkä kuva -> keskitetään miinustamalla 1 x suunnasta
	healthBarText->render(x - cx -1, y - cy-20, &gSpriteClips[1]);
	vihollinenText->render( x - cx, y - cy );
}

void Vihollinen::setVelocity(float v) {
	velocity = v;
}

int Vihollinen::merkki(float f) {
	if (f > 0) return 1;
	return (f == 0) ? 0 : -1;
}

int Vihollinen::getHp(){
	return hp;
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