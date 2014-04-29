#ifndef KAUPUNKI_H
#define KAUPUNKI_H

#include "Tekstuurit.h"
#include "PeliTila.h"

class Kaupunki
{
public:
	Kaupunki(PeliTila* pelitila);
	//~Kaupunki(void);
	void lataaKuvat();
	void avaaLaivatelakka();
	void avaaTaverna();
	void avaaAsepaja();
	void avaaRautapaja();
	void handleEvent();
	void setTaustaTexture(Tekstuurit tausta);
	void setTaloTexture(Tekstuurit talo);
	void setLaituriTexture(Tekstuurit laituri);
	

private:
	//tekstuurit

	PeliTila* pelitila;

	Tekstuurit talo;
	SDL_Rect taloClip[8];

	Tekstuurit kyla;
	SDL_Rect kyla_rect;
	SDL_Rect taloRau_rect;
	SDL_Rect taloAse_rect;
	SDL_Rect taloTela_rect;
	SDL_Rect taloTave_rect;

	Tekstuurit laituri;
	SDL_Rect laituri_rect;
	SDL_Rect laituriClip[2];

	SDL_Event kylaEvent;


	bool taloRauHoover, taloAseHoover, taloTelaHoover, taloTaveHoover, laituriHoover;
	bool quit;
};
#endif
