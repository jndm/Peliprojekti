#pragma once
#ifndef KAUPUNKI_H
#define KAUPUNKI_H

class Kaupunki
{
public:
	Kaupunki(SDL_Renderer* gRend);
	//~Kaupunki(void);
	void lataaKuvat();
	void avaaLaivatelakka();
	void avaaTaverna();
	void avaaAsepaja();
	void avaaRautapaja();
	void handleEvent();

private:
	//tekstuurit

	SDL_Texture* taloAse_kuva;
	SDL_Rect taloAse_rect;

	SDL_Texture* taloTave_kuva;
	SDL_Rect taloTave_rect;

	SDL_Texture* taloTela_kuva;
	SDL_Rect taloTela_rect;

	SDL_Texture* taloRau_kuva;
	SDL_Rect taloRau_rect;

	SDL_Texture* kyla_kuva;
	SDL_Rect kyla_rect;


	SDL_Event kylaEvent;
	SDL_Renderer* gRenderer;

	bool quit;
};
#endif
