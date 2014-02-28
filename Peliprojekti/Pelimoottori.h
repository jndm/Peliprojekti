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

class Pelimoottori {
private:
	//Ruuduun koko
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	int LEVEL_WIDTH;
	int LEVEL_HEIGHT;
	float FRAMETIMESTEP;

	//Käynnistää sdl:n ja luo ikkunan
	bool init();

	//Main loop
	void mainLoop();

	//lataa kuvia (Ei käytössä atm)
	bool loadMedia();

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
	Kamera camera;

public:
	Pelimoottori(void);
	~Pelimoottori(void);
	int start();
};

#endif