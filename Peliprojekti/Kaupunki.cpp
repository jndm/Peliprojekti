#include "Kaupunki.h"



Kaupunki::Kaupunki(PeliTila* tila)
{
	

	pelitila = tila;
	taloRauHoover = false;
	taloAseHoover = false;
	taloTelaHoover = false;
	taloTaveHoover = false;


	//luodaan talot
	//Asepaja	
	int y=0;
	for(int i=0; i<4; i++)
	{
		for(int k=0; k<2; k++)
		{
			taloClip[y].x = 0 + i*80;
			taloClip[y].y = 0 + k*80;
			taloClip[y].w = 80;
			taloClip[y].h = 80;
			y++;
		}
	}
		
		
	
	taloAse_rect.x = 76;
	taloAse_rect.y = 23;
	taloAse_rect.w = 80;
	taloAse_rect.h = 80;

	//Rautapaja	
	
	taloRau_rect.x = 473;
	taloRau_rect.y = 61;
	taloRau_rect.w = 80;
	taloRau_rect.h = 80;
	
	//Taverna	
	taloTave_rect.x = 365;
	taloTave_rect.y = 210;
	taloTave_rect.w = 80;
	taloTave_rect.h = 80;

	//Telakka
	taloTela_rect.x = 28;
	taloTela_rect.y = 254;
	taloTela_rect.w = 80;
	taloTela_rect.h = 80;
	
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
		if(taloRauHoover)
		{
			talo.render(taloRau_rect.x,taloRau_rect.y,&taloClip[1]);
		}else{
			talo.render(taloRau_rect.x,taloRau_rect.y,&taloClip[0]);
		}
		if(taloAseHoover)
		{
			talo.render(taloAse_rect.x,taloAse_rect.y,&taloClip[7]);
		}else{
			talo.render(taloAse_rect.x,taloAse_rect.y,&taloClip[6]);
		}
		if(taloTelaHoover)
		{
			talo.render(taloTela_rect.x,taloTela_rect.y,&taloClip[3]);
		}else{
			talo.render(taloTela_rect.x,taloTela_rect.y,&taloClip[2]);
		}
		if(taloTaveHoover)
		{
			talo.render(taloTave_rect.x,taloTave_rect.y,&taloClip[5]);
		}else{
			talo.render(taloTave_rect.x,taloTave_rect.y,&taloClip[4]);
		}

			
			

		
			
			
		/*
		talo.render(taloRau_rect.x,taloRau_rect.y);
		talo.render(taloTave_rect.x,taloTave_rect.y);
		talo.render(taloTela_rect.x,taloTela_rect.y);
		*/
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
	int x,y;

	if(kylaEvent.type == SDL_QUIT)
	{
		quit = true;
	}

	if(kylaEvent.type == SDL_MOUSEBUTTONDOWN)
	{
		//hiiren paikka
		
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

	else if(kylaEvent.type == SDL_MOUSEMOTION)
	{
		x = kylaEvent.motion.x;
		y = kylaEvent.motion.y;

		if(x > taloRau_rect.x && x < (taloRau_rect.x + taloRau_rect.w) && y > taloRau_rect.y && y < (taloRau_rect.y + taloRau_rect.h))
		{
			taloRauHoover = true;
		}else{
			taloRauHoover = false;
		}

		if(x > taloAse_rect.x && x < (taloAse_rect.x + taloAse_rect.w) && y > taloAse_rect.y && y < (taloAse_rect.y + taloAse_rect.h))
		{
			taloAseHoover = true;
		}else{
			taloAseHoover = false;
		}

		if(x > taloTave_rect.x && x < (taloTave_rect.x + taloTave_rect.w) && y > taloTave_rect.y && y < (taloTave_rect.y + taloTave_rect.h))
		{
			taloTaveHoover = true;
		}else{
			taloTaveHoover = false;
		}

		if(x > taloTela_rect.x && x < (taloTela_rect.x + taloTela_rect.w) && y > taloTela_rect.y && y < (taloTela_rect.y + taloTela_rect.h))
		{
			taloTelaHoover = true;
		}else{
			taloTelaHoover = false;
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

void Kaupunki::setTaloTexture(Tekstuurit tekstuuri)
{
	talo = tekstuuri;
}

void Kaupunki::setTaustaTexture(Tekstuurit tekstuuri)
{
	kyla = tekstuuri;
}

