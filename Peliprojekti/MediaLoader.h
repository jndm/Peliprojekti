#pragma once
#ifndef MEDIALOADER_H
#define MEDIALOADER_H

#include <SDL.h>
#include <SDL_image.h>
#include "Tekstuurit.h"
#include "Pelihahmo.h"
#include "Maailma.h"

class Maailma;

class MediaLoader{
public:
	//lataa kuvia
	bool loadMedia(SDL_Renderer* gRenderer);
	MediaLoader(Maailma* m);

private:
	Pelihahmo pelihahmo;
	Tekstuurit pelihahmoText;
	Tekstuurit taustaText;
	Maailma* maailma;
};

#endif