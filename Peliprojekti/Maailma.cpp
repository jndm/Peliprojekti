#include "Maailma.h"

Maailma::Maailma(Pelimoottori* pelimoottori){
	SCREEN_WIDTH = pelimoottori->getSCREENWIDTH();
	SCREEN_HEIGHT = pelimoottori->getSCREENHEIGHT();
	LEVEL_WIDTH = pelimoottori->getLEVELWIDTH();
	LEVEL_HEIGHT = pelimoottori->getLEVELHEIGHT();
	luoKentanRajat();
	pelihahmo = new Pelihahmo();
	camera.alusta(SCREEN_WIDTH, SCREEN_HEIGHT, pelihahmo);
	gui = pelimoottori->getGUI();
}



void Maailma::render(){
	camera.moveCamera(SCREEN_WIDTH, SCREEN_HEIGHT, LEVEL_WIDTH, LEVEL_HEIGHT);
	tausta.render( 0, 0, &camera.getCamera() );
	pelihahmo->render( camera.getCameraX(), camera.getCameraY() );
	for(std::vector<Vihollinen*>::iterator it = viholliset.begin(); it != viholliset.end(); ++it) {
		(*it)->render(camera.getCameraX(), camera.getCameraY());
	}
	for(std::vector<Tykinkuula*>::iterator it = pelihahmo->getCannonballs()->begin(); it != pelihahmo->getCannonballs()->end(); ++it) {
		(*it)->render(camera.getCameraX(), camera.getCameraY());
	}
	int i=0;
	for(std::vector<Rajahdys>::iterator it = rajahdykset.begin(); it != rajahdykset.end(); ++i) {
		if(renderExplosion(*it)){       //Renderöidään räjähdykset ja poistetaan ne kun renderöinti on valmis
			it = rajahdykset.erase(it);
		}
		else it++;
	}
	i=0;
	for(RajaNelio rj : rajaneliot){
		rajatext.render(rj.x - camera.getCameraX(), rj.y -camera.getCameraY(), &rajat[i], rj.kulma);
		i++;
	}
	gui->render(camera.getCameraX(), camera.getCameraY());
}

void Maailma::move(float timestep){
	pelihahmo->move(timestep);

	//liikutetaan tykinkuulia ja tuhotaan ne kun ne tulevat tarpeeksi pitkälle
	int i=0;
	for(std::vector<Tykinkuula*>::iterator it = pelihahmo->getCannonballs()->begin(); it != pelihahmo->getCannonballs()->end(); ++i) {
		(*it)->move(timestep);
		if((*it)->ifRdyToBeDestroyed()){
			it = pelihahmo->getCannonballs()->erase(it);
		}
		else it++;
	}
}

void Maailma::checkCollisions(){
	//Tarkistetaan tykinkuulan törmäys, merkitään törmäyspaikka animaatiota varten talteen ja poistetaan tykinkuula
	int i=0;
	for(std::vector<Vihollinen*>::iterator itv = viholliset.begin(); itv != viholliset.end(); ++i){
		for(std::vector<Tykinkuula*>::iterator itt = pelihahmo->getCannonballs()->begin(); itt != pelihahmo->getCannonballs()->end(); ++i) {
			if((*itv)->checkIfCannonballHit((*itt))){
				rajahdys.x = (*itt)->getX();
				rajahdys.y = (*itt)->getY();
				rajahdys.valmis = false;
				rajahdykset.push_back(rajahdys);
				(*itv)->lowerHp(1);
				itt = pelihahmo->getCannonballs()->erase(itt);
			}
			else itt++;
		}
		if((*itv)->getHp() == 0){
			itv = viholliset.erase(itv);
		}
		else itv++;
	}
}

Pelihahmo* Maailma::getPelihahmo(){
	return pelihahmo;
}

void Maailma::createStartingEnemys(){
	srand(time(0));
	//viholliset.push_back(new Vihollinen((rand()%LEVEL_WIDTH + 1), (rand()%LEVEL_HEIGHT + 1), enemyTexture));
	for(int i=0; i<1; i++){
		int x = rand()%500 + 1;
		int y = rand()%500 + 1;

		//printf("%d",i);
		if(!viholliset.empty()){
			for(int j=0; j<viholliset.size(); ++j){
				if(x+viholliset[j]->getWidth() > viholliset[j]->getX() && x < viholliset[j]->getX()+viholliset[j]->getWidth()    
					&&  y+viholliset[j]->getHeight() > viholliset[j]->getY() && y < viholliset[j]->getY()+viholliset[j]->getHeight())
				{
					x = rand()%500 + 1;
					y = rand()%500 + 1;
					j=0;
				}
			}
		}
		viholliset.push_back(new Vihollinen(x, y, &enemyTexture, &enemyHpBarText));
	}
}

void Maailma::setEnemyTexture(Tekstuurit enemyText) {
	enemyTexture = enemyText;
}

void Maailma::setEnemyHealthBarTexture(Tekstuurit enemyHBText){
	enemyHpBarText = enemyHBText;
}

void Maailma::setTaustaTexture(Tekstuurit taustaText) {
	tausta = taustaText;
}

void Maailma::setRajaTexture(Tekstuurit t) {
	rajatext = t;
}

void Maailma::setExplosionTexture(Tekstuurit enemyText){
	explosionTexture = enemyText;
	for(int i=0; i<FRAMES_IN_SPRITESHEET; ++i){
		gSpriteClips[i].x = i*30;
		gSpriteClips[i].y = 0;
		gSpriteClips[i].w = 30;
		gSpriteClips[i].h = 30;
	}
	explosionFrame = 0;
}

bool Maailma::renderExplosion(Rajahdys r){
	explosionTexture.render(r.x - camera.getCameraX(), r.y - camera.getCameraY(), &gSpriteClips[explosionFrame/6]);
	explosionFrame++;
	if( explosionFrame / 6 >= FRAMES_IN_SPRITESHEET ){
		explosionFrame=0;
		return true;
	}else
		return false;
}

void Maailma::luoKentanRajat(){
	RajaNelio rj0 = {314,92,213,90,155};
	rajat[0].x = 0;
	rajat[0].y = 0;
	rajat[0].w = rj0.w;
	rajat[0].h = rj0.h;
	rajaneliot[0] = rj0;
	RajaNelio rj1 = {62,165,56,442,0};
	rajat[1].x = 0;
	rajat[1].y = 0;
	rajat[1].w = rj1.w;
	rajat[1].h = rj1.h;
	rajaneliot[1] = rj1;
	RajaNelio rj2 = {86,636,166,40,45};
	rajat[2].x = 0;
	rajat[2].y = 0;
	rajat[2].w = rj2.w;
	rajat[2].h = rj2.h;
	rajaneliot[2] = rj2;
	RajaNelio rj3 = {213,734,225,40,115};
	rajat[3].x = 0;
	rajat[3].y = 0;
	rajat[3].w = rj3.w;
	rajat[3].h = rj3.h;
	rajaneliot[3] = rj3;
	RajaNelio rj4 = {38,986,85,841,0};
	rajat[4].x = 0;
	rajat[4].y = 0;
	rajat[4].w = rj4.w;
	rajat[4].h = rj4.h;
	rajaneliot[4] = rj4;
	RajaNelio rj5 = {122,1799,328,28,0};
	rajat[5].x = 0;
	rajat[5].y = 0;
	rajat[5].w = rj5.w;
	rajat[5].h = rj5.h;
	rajaneliot[5] = rj5;
	RajaNelio rj6 = {550,1750,105,27,160};
	rajat[6].x = 0;
	rajat[6].y = 0;
	rajat[6].w = rj6.w;
	rajat[6].h = rj6.h;
	rajaneliot[6] = rj6;
	RajaNelio rj7 = {553,1779,116,30,40};
	rajat[7].x = 0;
	rajat[7].y = 0;
	rajat[7].w = rj7.w;
	rajat[7].h = rj7.h;
	rajaneliot[7] = rj7;
	RajaNelio rj8 = {669,1874,923,39,0};
	rajat[8].x = 0;
	rajat[8].y = 0;
	rajat[8].w = rj8.w;
	rajat[8].h = rj8.h;
	rajaneliot[8] = rj8;
	RajaNelio rj9 = {1939,1615,350,31,140};
	rajat[9].x = 0;
	rajat[9].y = 0;
	rajat[9].w = rj9.w;
	rajat[9].h = rj9.h;
	rajaneliot[9] = rj9;
	RajaNelio rj10 = {1709,1086,551,49,80};
	rajat[10].x = 0;
	rajat[10].y = 0;
	rajat[10].w = rj10.w;
	rajat[10].h = rj10.h;
	rajaneliot[10] = rj10;
	RajaNelio rj11 = {1858,881,192,36,125};
	rajat[11].x = 0;
	rajat[11].y = 0;
	rajat[11].w = rj11.w;
	rajat[11].h = rj11.h;
	rajaneliot[11] = rj11;
	RajaNelio rj12 = {1858,124,95,757,0};
	rajat[12].x = 0;
	rajat[12].y = 0;
	rajat[12].w = rj12.w;
	rajat[12].h = rj12.h;
	rajaneliot[12] = rj12;
	RajaNelio rj13 = {1230,77,630,50,0};
	rajat[13].x = 0;
	rajat[13].y =0;
	rajat[13].w = rj13.w;
	rajat[13].h = rj13.h;
	rajaneliot[13] = rj13;
	RajaNelio rj14 = {335,0,895,90,0};
	rajat[14].x = 0;
	rajat[14].y = 0;
	rajat[14].w = rj14.w;
	rajat[14].h = rj14.h;
	rajaneliot[14] = rj14;
}