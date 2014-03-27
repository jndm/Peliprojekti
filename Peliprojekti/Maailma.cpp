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
	}
	for(std::vector<Tykinkuula*>::iterator it = pelihahmo->getCannonballs()->begin(); it != pelihahmo->getCannonballs()->end(); ++it) {
		(*it)->render(camera.getCameraX(), camera.getCameraY());
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
	int i=0;
	for(std::vector<Vihollinen*>::iterator itv = viholliset.begin(); itv != viholliset.end(); ++itv){
		for(std::vector<Tykinkuula*>::iterator itt = pelihahmo->getCannonballs()->begin(); itt != pelihahmo->getCannonballs()->end(); ++i) {
			if((*itv)->checkIfCannonballHit((*itt))){
				std::thread t(&Maailma::renderExplosion, this, (*itt)->getX(), (*itt)->getY());
				t.detach();
				itt = pelihahmo->getCannonballs()->erase(itt);
			}
			else itt++;
		}
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
		viholliset.push_back(new Vihollinen(x, y, &enemyTexture));
	}
}

void Maailma::setEnemyTexture(Tekstuurit enemyText) {
	enemyTexture = enemyText;
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

void Maailma::renderExplosion(float x, float y){
	long animationDelay = 300;
	long time = 0;
	while( explosionFrame < FRAMES_IN_SPRITESHEET ){
		if(SDL_GetTicks() > time + animationDelay){
			explosionTexture.render( x - camera.getCameraX(), y - camera.getCameraY() , &gSpriteClips[explosionFrame]);	
			printf("Piirretaan rajahdysta pisteeseen x: %d, y: %d frame: %d\n", (int)(x - camera.getCameraX()), (int)(y - camera.getCameraY()), (int)(explosionFrame));
			explosionFrame++;
			time = SDL_GetTicks();
		}
	}
	explosionFrame = 0;
}
