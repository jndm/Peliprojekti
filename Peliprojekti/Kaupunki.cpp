#include "Kaupunki.h"
#include "Pelimoottori.h"


using namespace std;


Kaupunki::Kaupunki(SDL_Renderer* gRend)
{
	
	quit = false;

	gRenderer = gRend;

	//luodaan talot
	//Asepaja
	taloAse_kuva = NULL;
	taloAse_kuva = IMG_LoadTexture(gRenderer,"talo.bmp");
	taloAse_rect.x = 20;
	taloAse_rect.y = 20;
	taloAse_rect.w = 20;
	taloAse_rect.h = 20;

	//Rautapaja
	taloRau_kuva = NULL;
	taloRau_kuva = IMG_LoadTexture(gRenderer,"talo.bmp");
	taloRau_rect.x = 100;
	taloRau_rect.y = 20;
	taloRau_rect.w = 20;
	taloRau_rect.h = 20;

	//Taverna
	taloTave_kuva = NULL;
	taloTave_kuva = IMG_LoadTexture(gRenderer,"talo.bmp");
	taloTave_rect.x = 20;
	taloTave_rect.y = 100;
	taloTave_rect.w = 20;
	taloTave_rect.h = 20;

	//Telakka
	taloTela_kuva = NULL;
	taloTela_kuva = IMG_LoadTexture(gRenderer,"talo.bmp");
	taloTela_rect.x = 100;
	taloTela_rect.y = 100;
	taloTela_rect.w = 20;
	taloTela_rect.h = 20;

	//Kylä
	kyla_kuva = NULL;
	kyla_kuva = IMG_LoadTexture(gRenderer,"kyla.bmp");

	kyla_rect.x = 0;
	kyla_rect.y = 0;
	kyla_rect.w = 400;
	kyla_rect.h = 400;
}


/*Kaupunki::~Kaupunki(void)
{
}*/

void Kaupunki::lataaKuvat()
{
	quit = false;

	while(!quit)
	{

		while( SDL_PollEvent( &kylaEvent ) != 0 )
			{
				handleEvent();
			}
		SDL_RenderClear(gRenderer);

		SDL_RenderCopy(gRenderer,kyla_kuva, NULL, &kyla_rect);
		SDL_RenderCopy(gRenderer,taloAse_kuva, NULL, &taloAse_rect);
		SDL_RenderCopy(gRenderer,taloTave_kuva, NULL, &taloTave_rect);
		SDL_RenderCopy(gRenderer,taloRau_kuva, NULL, &taloRau_rect);
		SDL_RenderCopy(gRenderer,taloTela_kuva, NULL, &taloTela_rect);
	}
	

	//SDL_DestroyWindow(gWindow);
	SDL_DestroyRenderer(gRenderer);
	//gWindow = NULL;
	gRenderer = NULL;
}

void Kaupunki::avaaAsepaja()
{
	printf("asepaja toimaa");
}

void Kaupunki::avaaLaivatelakka()
{
	printf("telakka toimaa");
}

void Kaupunki::avaaRautapaja()
{
	printf("Rautapaja toimaa");
}

void Kaupunki::avaaTaverna()
{
	printf("Taverna toimaa");
}

void Kaupunki::handleEvent()
{
	if(kylaEvent.type == SDL_QUIT)
	{
		quit = true;
	}

	if(kylaEvent.type == SDL_MOUSEBUTTONDOWN)
	{
		//hiiren paikka
		int x,y;
		SDL_GetMouseState( &x, &y );

		if(x > taloAse_rect.x && x < (taloAse_rect.x + taloAse_rect.w) && y > taloAse_rect.y && y < (taloAse_rect.y + taloAse_rect.h))
		{
			avaaAsepaja();
		}

		if(x > taloRau_rect.x && x < (taloRau_rect.x + taloRau_rect.w) && y > taloRau_rect.y && y < (taloRau_rect.y + taloRau_rect.h))
		{
			avaaRautapaja();
		}

		if(x > taloTave_rect.x && x < (taloTave_rect.x + taloTave_rect.w) && y > taloTave_rect.y && y < (taloTave_rect.y + taloTave_rect.h))
		{
			avaaTaverna();
		}

		if(x > taloTela_rect.x && x < (taloTela_rect.x + taloTela_rect.w) && y > taloTela_rect.y && y < (taloTela_rect.y + taloTela_rect.h))
		{
			avaaLaivatelakka();
		}
	}
}