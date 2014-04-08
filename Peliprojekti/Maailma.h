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
	Tekstuurit* getEnemyTexture() {
		return &enemyTexture;
	}
	Tekstuurit* getTargetTexture() {
		return &targetTexture;
	}
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
	SDL_Rect gSpriteClips[FRAMES_IN_SPRITESHEET];
	Tekstuurit targetTexture;
	GUI* gui;
	Vihollinen* vihollinen;
	vector<Vihollinen*> viholliset;
	int explosionFrame;
	bool renderExplosion(Rajahdys r);
	vector<Rajahdys> rajahdykset;
	Rajahdys rajahdys;
};
#endif