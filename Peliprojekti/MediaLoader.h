#pragma once
#ifndef MEDIALOADER_H
#define MEDIALOADER_H

#include <SDL.h>
#include <SDL_image.h>
#include "Tekstuurit.h"
#include "Pelihahmo.h"
#include "GUI.h"
#include "Maailma.h"
#include "MainMenu.h"
#include "Kaupunki.h"

class Maailma;

class MediaLoader{
public:
	//lataa kuvia
	bool loadMedia(SDL_Renderer* gRenderer, int state);
	MediaLoader(Maailma* m, GUI* gui, MainMenu* mm, Kaupunki* k);

private:
	//MainMenun tekstuurit
	MainMenu* mainmenu;
	Tekstuurit mainmenuBtext;
	Tekstuurit mainmenuTitletext;

	//Maailman tekstuurit
	Pelihahmo pelihahmo;
	Tekstuurit pelihahmoText;
	Tekstuurit taustaText;
	Tekstuurit ssbTeksture;
	Tekstuurit ssButton;
	Tekstuurit enemyText;
	Tekstuurit cannonballText;
	Tekstuurit explosionText;
	Tekstuurit enemyHealthBarText;
	Tekstuurit targetText;
	Tekstuurit talo_kuva;
	Tekstuurit kyla_kuva;
	Tekstuurit laituri_kuva;
	Maailma* maailma;
	GUI* gui;
	Kaupunki* kaupunki;
};

#endif