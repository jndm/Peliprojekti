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
	void setRautapajaTexture(Tekstuurit talo);
	void setTavernaTexture(Tekstuurit talo);
	void setTelakkaTexture(Tekstuurit talo);

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

	SDL_Event kylaEvent;


	bool taloRauHoover, taloAseHoover, taloTelaHoover, taloTaveHoover;
	bool quit;
};
#endif
