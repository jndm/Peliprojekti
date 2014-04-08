#include "Kaupunki.h"



Kaupunki::Kaupunki(PeliTila* tila)
{
	

	pelitila = tila;


	//luodaan talot
	//Asepaja	
	taloAse_rect.x = 100;
	taloAse_rect.y = 100;
	taloAse_rect.w = 50;
	taloAse_rect.h = 50;

	//Rautapaja	
	taloRau_rect.x = 485;
	taloRau_rect.y = 90;
	taloRau_rect.w = 80;
	taloRau_rect.h = 80;

	//Taverna	
	taloTave_rect.x = 200/*315*/;
	taloTave_rect.y = 200;
	taloTave_rect.w = 50;
	taloTave_rect.h = 50;

	//Telakka
	taloTela_rect.x = 85;
	taloTela_rect.y = 305;
	taloTela_rect.w = 50;
	taloTela_rect.h = 50;

	//Kylä
	kyla_rect.x = 0;
	kyla_rect.y = 0;
	kyla_rect.w = 640;
	kyla_rect.h = 480;
}


/*Kaupunki::~Kaupunki(void)
{
}*/

void Kaupunki::lataaKuvat()
{
	


		while( SDL_PollEvent( &kylaEvent ) != 0 )
			{
				handleEvent();
			}

		kyla.render(0,0,&kyla_rect);
		taloAse.render(taloAse_rect.x,taloAse_rect.y,&taloAse_rect);
		taloRau.render(taloRau_rect.x,taloRau_rect.y,&taloRau_rect);
		taloTave.render(taloTave_rect.x,taloTave_rect.y,&taloTave_rect);
		taloTela.render(taloTela_rect.x,taloTela_rect.y,&taloTave_rect);
	
	//SDL_DestroyWindow(gWindow);
	//SDL_DestroyRenderer(gRenderer);
	//gWindow = NULL;
	//gRenderer = NULL;
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
	if(kylaEvent.type == SDL_KEYDOWN)
	{
		switch( kylaEvent.key.keysym.sym ){
		case SDLK_m:
			printf("maailmaan");
			pelitila->setTila(pelitila->maailmassa);
			break;
		}
	}
}

void Kaupunki::setAsepajaTexture(Tekstuurit tekstuuri)
{
	taloAse = tekstuuri;
}

void Kaupunki::setTavernaTexture(Tekstuurit tekstuuri)
{
	taloTave = tekstuuri;
}

void Kaupunki::setRautapajaTexture(Tekstuurit tekstuuri)
{
	taloRau = tekstuuri;
}

void Kaupunki::setTelakkaTexture(Tekstuurit tekstuuri)
{
	taloTela = tekstuuri;
}

void Kaupunki::setTaustaTexture(Tekstuurit tekstuuri)
{
	kyla = tekstuuri;
}

