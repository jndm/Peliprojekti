#pragma once
#ifndef PELIMOOTTORI_H
#define PELIMOOTTORI_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "Pelihahmo.h"
#include "Tekstuurit.h"
#include "Kamera.h"
#include "Maailma.h"
#include "MediaLoader.h"

class Maailma;
class MediaLoader;

class Pelimoottori {
private:
	//Ruudun koko
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	int LEVEL_WIDTH;
	int LEVEL_HEIGHT;
	float FRAMETIMESTEP;

	//Käynnistää sdl:n ja luo ikkunan
	bool init();

	//Main loop
	void mainLoop();

	//Kutsutaan suljettaessa ja vapautetaan muisti
	void close();

	//Piirto metodi
	void draw(int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip);

	//Kuvan latausta varten tehty metodi (ei käytössä)
	SDL_Texture* loadTexture( std::string path );
	
	//Näppäimistön käsittelijä
	void handleEvent();

	//Siirrä kameraa
	void moveCamera();

	//Ikkuna johon piirretään
	SDL_Window* gWindow;

	//Renderöijä
	SDL_Renderer* gRenderer;

	//Event handler
	SDL_Event e;

	Pelihahmo* pelihahmo;
	bool quit;
	Tekstuurit nelio, tausta;
	Maailma* maailma;
	MediaLoader* mediaLoader;

public:
	Pelimoottori(void);
	~Pelimoottori(void);
	int start();
	int getSCREENWIDTH(){return SCREEN_WIDTH;}
	int getSCREENHEIGHT(){return SCREEN_HEIGHT;}
	int getLEVELWIDTH(){return LEVEL_WIDTH;}
	int getLEVELHEIGHT(){return LEVEL_HEIGHT;}
};
#endif