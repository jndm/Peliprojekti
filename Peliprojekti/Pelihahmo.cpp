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
	suunta=0;
	locxmap=x;
	locymap=y;
	kaantyminen=false;
}

Pelihahmo::~Pelihahmo(void){

}


void Pelihahmo::move(float fts){
	if(kaantyminen){
		int s=kaannossuunta();
		if(s>0){
			//tee oikealle liikkuminen
			suunta+=1;
			if(suunta>180)
				suunta=suunta-360;
		}
		else if(s==0){
			//tee suoraan liikkuminen
		}
		else if(s<0){
			//tee vasemmalle liikkuminen
			suunta-=1;
			if(suunta<-180)
				suunta=suunta+360;
		}
	}
	//printf("%f\n",suunta);
	x+=dx*fts*(std::cos(suunta*M_PI/180));
	y+=dy*fts*(std::sin(suunta*M_PI/180));

	//float suuntax=cos(suunta);
	//float suuntay=sin(suunta);
	//float position = ( (Bx-Ax)*(Y-Ay) - (By-Ay)*(X-Ax) );
	//printf("x: %f y: %f liikeX: %f liikeY: %f\n",x,y,dx,dy);
}

void Pelihahmo::setKohde(int mx, int my){
	locxmap=mx+kamerax;
	locymap=my+kameray;
}

int Pelihahmo::kaannossuunta(){//int s>0 oikealle, s=0 suoraan, s<0 vasemmalle

	int deltax=locxmap-(x+width/2);
	int deltay=locymap-(y+height/2);
	float angleInDegrees = atan2(deltay, deltax) * 180 / M_PI;

	//printf("%f\n",angleInDegrees);
	if(angleInDegrees - suunta < 1 && angleInDegrees - suunta > -1){
		return 0;
	}else{
		if(angleInDegrees>0&&suunta>0&&angleInDegrees>suunta){
			//printf("oik\n");
			//k‰‰nny oikealle
			return 1;
		}
		else if(angleInDegrees>=0&&suunta>=0&&angleInDegrees<suunta){
			//printf("vase\n");
			//k‰‰nny vasemmalle
			return -1;
		}
		else if(angleInDegrees<=0&&suunta>=0&&(180-suunta)>angleInDegrees*(-1)){
			//printf("vase\n");
			//k‰‰nny vasemmalle
			return -1;
		}
		else if(angleInDegrees<=0&&suunta>=0&&(180-suunta)<angleInDegrees*(-1)){
			//printf("oik\n");
			//k‰‰nny oikealle
			return 1;
		}


		else if(angleInDegrees<=0&&suunta<=0&&angleInDegrees>suunta){
			//printf("oik\n");
			//k‰‰nny oikealle
			return 1;
		}
		else if(angleInDegrees<=0&&suunta<=0&&angleInDegrees<suunta){
			//printf("vase\n");
			//k‰‰nny vasemmalle
			return -1;
		}
		else if(angleInDegrees>=0&&suunta<=0&&(180+suunta)<angleInDegrees){
			//printf("vase\n");
			//k‰‰nny vasemmalle
			return -1;
		}
		else if(angleInDegrees>=0&&suunta<=0&&(180+suunta)>angleInDegrees){
			//printf("oik\n");
			//k‰‰nny oikealle
			return 1;
		}


		else if(angleInDegrees>=0&&suunta>=0&&angleInDegrees-suunta==180||angleInDegrees-suunta==-180){
			//printf("vase\n");
			//k‰‰nny vasemmalle
			return -1;
		}
		else if(angleInDegrees>=0&&suunta<=0&&angleInDegrees-suunta==180||angleInDegrees-suunta==-180){
			//printf("vase\n");
			//k‰‰nny vasemmalle
			return -1;
		}
		else if(angleInDegrees<=0&&suunta>=0&&angleInDegrees-suunta==180||angleInDegrees-suunta==-180){
			//printf("vase\n");
			//k‰‰nny vasemmalle
			return -1;
		}
		else if(angleInDegrees<=0&&suunta<=0&&angleInDegrees-suunta==180||angleInDegrees-suunta==-180){
			//printf("vase\n");
			//k‰‰nny vasemmalle
			return -1;
		}

		else{
			//printf("suoraan\n");
			//kulje suoraa
			return 0;
		}
	}
	/*
	float kulma = atan2(deltax, deltay);
	kulma = (kulma + M_PI) - (suunta*M_PI/180 + M_PI);
	if(fabs(kulma) > M_PI) {
	kulma = kulma - merkki(kulma)*2*M_PI;
	}
	if(kulma < -M_PI/180) {
	return 1;
	} else if(kulma > M_PI/180) {
	return -1;
	} else {
	return 0;
	}*/

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
	kamerax = _camX;
	kameray = _camY;
	//N‰yt‰ neliˆ kameran suhteen
	pelihahmoText.render( (int)(x - kamerax), (int)(y - kameray) , NULL, suunta);

}

void Pelihahmo::setKaantyminen(bool _kaantyminen){
	kaantyminen = _kaantyminen;
}

//T‰lle jotain fiksumpaa ratkaisua?
void Pelihahmo::setCharacterTexture(Tekstuurit tekstuuri){
	pelihahmoText = tekstuuri;
}

void Pelihahmo::setCannonballTexture(Tekstuurit tekstuuri){
	cannonballText = tekstuuri;
}

void Pelihahmo::setXVelocity(float vx){
	dx = vx;
}

void Pelihahmo::setYVelocity(float vy){
	dy = vy;
}
void Pelihahmo::ammu(int tykki){

	if(SDL_GetTicks() > lastShootTime + shootingDelay){
		cannonballs.push_back(new Tykinkuula(this, &cannonballText, suunta, tykki, kaannossuunta()));
		lastShootTime = SDL_GetTicks();
	}
}

int Pelihahmo::merkki(float f) {
	if (f > 0) return 1;
	return (f == 0) ? 0 : -1;
}

bool Pelihahmo::checkIfInArea(int rx, int ry, int rwidth, int rheight){
	int hit = true;

	if(x > rx+rwidth){ hit = false; }
	else if( x + width < rx){ hit = false; }
	else if( y > ry+rheight){ hit = false; }
	else if( y + height < ry){ hit = false; }

	return hit;
}

void Pelihahmo::setX(float _x){
	x = _x;
}

void Pelihahmo::setY(float _y){
	y = _y;
}