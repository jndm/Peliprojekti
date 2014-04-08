#pragma once
#ifndef MEDIALOADER_H
#define MEDIALOADER_H

#include <SDL.h>
#include <SDL_image.h>
#include "Tekstuurit.h"
#include "Pelihahmo.h"
#include "GUI.h"
#include "Maailma.h"
#include "Kaupunki.h"

class Maailma;

class MediaLoader{
public:
	//lataa kuvia
	bool loadMedia(SDL_Renderer* gRenderer);
	MediaLoader(Maailma* m, GUI* gui, Kaupunki* k);

private:
	Pelihahmo pelihahmo;
	Tekstuurit pelihahmoText;
	Tekstuurit taustaText;
	Tekstuurit ssbTeksture;
	Tekstuurit ssButton;
	Tekstuurit enemyText;
	Tekstuurit taloAse_kuva;
	Tekstuurit taloTave_kuva;
	Tekstuurit taloTela_kuva;
	Tekstuurit taloRau_kuva;
	Tekstuurit kyla_kuva;
	Maailma* maailma;
	GUI* gui;
	Kaupunki* kaupunki;
};

#endif