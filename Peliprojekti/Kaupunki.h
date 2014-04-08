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
	void setAsepajaTexture(Tekstuurit talo);
	void setRautapajaTexture(Tekstuurit talo);
	void setTavernaTexture(Tekstuurit talo);
	void setTelakkaTexture(Tekstuurit talo);

private:
	//tekstuurit

	PeliTila* pelitila;

	Tekstuurit taloAse;
	SDL_Rect taloAse_rect;

	Tekstuurit taloTave;
	SDL_Rect taloTave_rect;

	Tekstuurit taloTela;
	SDL_Rect taloTela_rect;

	Tekstuurit taloRau;
	SDL_Rect taloRau_rect;

	Tekstuurit kyla;
	SDL_Rect kyla_rect;


	SDL_Event kylaEvent;

	bool quit;
};
#endif
