#pragma once
#ifndef MAAILMA_H
#define MAAILMA_H

#include "Pelihahmo.h"
#include "Pelimoottori.h"
#include "Kamera.h"
#include "Tekstuurit.h"
#include "GUI.h"
#include "Vihollinen.h"
#include <vector>
#include <time.h>
#include <thread>
#include "Tykinkuula.h"

using namespace std;

class Pelimoottori;

struct RajaNelio{
	int x;
	int y;
	int w;
	int h;
};

struct Rajahdys{
	int x;
	int y;
	bool valmis;
};

class Maailma{
public:
	Maailma(Pelimoottori* pelimoottori);
	//~Maailma(void);
	void render();
	void move(float timestep);
	void setTaustaTexture(Tekstuurit taustaText);
	void setExplosionTexture(Tekstuurit explosionText);
	Pelihahmo* getPelihahmo();
	void createStartingEnemys();
	void setEnemyTexture(Tekstuurit enemyText);
	void setEnemyHealthBarTexture(Tekstuurit enemyHBText);
	void setTargetTexture(Tekstuurit targetText);
	void setCannonballTexture(Tekstuurit cannonballText);
	Tekstuurit* getEnemyTexture() {
		return &enemyTexture;
	}
	Tekstuurit* getTargetTexture() {
		return &targetTexture;
	}
	void setRajaTexture(Tekstuurit t);
	int getKameraloc();
	Kamera getCamera(){ return camera; }
	void checkCollisions();

private:
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	int LEVEL_WIDTH;
	int LEVEL_HEIGHT;
	Pelihahmo* pelihahmo;
	Kamera camera;
	Tekstuurit tausta;
	Tekstuurit enemyTexture;
	Tekstuurit enemyHpBarText;
	Tekstuurit explosionTexture;
	Tekstuurit cannonballTexture;
	Tekstuurit rajatext;
	SDL_Rect gSpriteClips[FRAMES_IN_SPRITESHEET];
	Tekstuurit targetTexture;
	GUI* gui;
	Vihollinen* vihollinen;
	vector<Vihollinen*> viholliset;
	int explosionFrame;
	bool renderExplosion(Rajahdys r);
	vector<Rajahdys> rajahdykset;
	void luoKentanRajat();
	Rajahdys rajahdys;
	RajaNelio rajaneliot[7];
};
#endif