#include "Maailma.h"

Maailma::Maailma(Pelimoottori* pelimoottori){
	SCREEN_WIDTH = pelimoottori->getSCREENWIDTH();
	SCREEN_HEIGHT = pelimoottori->getSCREENHEIGHT();
	LEVEL_WIDTH = pelimoottori->getLEVELWIDTH();
	LEVEL_HEIGHT = pelimoottori->getLEVELHEIGHT();

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
		for(std::vector<Tykinkuula*>::iterator it2 = (*it)->getCannonballs()->begin(); it2 != (*it)->getCannonballs()->end(); ++it2) {
			(*it2)->render(camera.getCameraX(), camera.getCameraY());
		}
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
	for(std::vector<Vihollinen*>::iterator it = viholliset.begin(); it != viholliset.end(); ++it) {
		(*it)->move(timestep);
		for(std::vector<Tykinkuula*>::iterator it2 = (*it)->getCannonballs()->begin(); it2 != (*it)->getCannonballs()->end(); ++i) {
			(*it2)->move(timestep);
			if((*it2)->ifRdyToBeDestroyed()){
				it2 = (*it)->getCannonballs()->erase(it2);
			}
			else it2++;
		}
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
	for(int i=0; i<3; i++){
		float x = rand()%500 + 1;
		float y = rand()%500 + 1;
		//float suunta = M_PI/(rand()%8-4);
		float suunta = 0;

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
		viholliset.push_back(new Vihollinen(x, y, suunta, pelihahmo, this));
		viholliset[viholliset.size() - 1]->setHealthBarText(&enemyHpBarText);
		viholliset[viholliset.size() - 1]->setVihollinenText(&enemyTexture);
		viholliset[viholliset.size() - 1]->setTargetText(&targetTexture);
		viholliset[viholliset.size() - 1]->setCannonballText(&cannonballTexture);
	}
}

void Maailma::setEnemyTexture(Tekstuurit enemyText) {
	enemyTexture = enemyText;
}

void Maailma::setEnemyHealthBarTexture(Tekstuurit enemyHBText){
	enemyHpBarText = enemyHBText;
}

void Maailma::setTargetTexture(Tekstuurit targetText) {
	targetTexture = targetText;
}

void Maailma::setTaustaTexture(Tekstuurit taustaText) {
	tausta = taustaText;
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

void Maailma::setCannonballTexture(Tekstuurit cannonballText) {
	cannonballTexture = cannonballText;
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
