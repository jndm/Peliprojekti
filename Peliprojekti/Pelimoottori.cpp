#include "Pelimoottori.h"

Pelimoottori::Pelimoottori(void){
	SCREEN_WIDTH = 640;
	SCREEN_HEIGHT = 480;
	LEVEL_WIDTH = 2048;
	LEVEL_HEIGHT = 2048;
	FRAMETIMESTEP = 1.f/60.f;
	sliderinLiikutus = false;
	gui = new GUI();
	pelitila = new PeliTila();
	kaupunki = new Kaupunki(pelitila);
	pelitila->setTila(pelitila->maailmassa);
	maailma = new Maailma(this);
	mediaLoader = new MediaLoader(maailma, gui, kaupunki);
	
}

Pelimoottori::~Pelimoottori(void){

}

bool Pelimoottori::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_SOFTWARE /*SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC*/ );
			if( gRenderer == NULL )
			{
				printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
					success = false;
				}
			}
		}
	}
	return success;
}

void Pelimoottori::close()
{
	//Destroy window	
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;
	delete mediaLoader;
	delete maailma;
	delete gui;
	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void Pelimoottori::handleEvent(){
	if( e.type == SDL_QUIT ){
		quit = true;
	}
	//Hiiren käsittely
	else if( e.type == SDL_MOUSEBUTTONDOWN){
		int x, y;
        SDL_GetMouseState( &x, &y );
		if(gui->checkIfHitSideBar(x, y)){
			gui->moveSpeedBarButton(y);
			maailma->getPelihahmo()->setXVelocity((480-y)/2, 1);
			sliderinLiikutus = true;
		}
		else
			maailma->getPelihahmo()->kaannossuunta(x,y);
	}else if( e.type == SDL_MOUSEBUTTONUP && sliderinLiikutus){
		sliderinLiikutus = false;
	}else if( e.type == SDL_MOUSEMOTION && sliderinLiikutus){
		int x, y;
        SDL_GetMouseState( &x, &y );
		gui->moveSpeedBarButton(y);
		maailma->getPelihahmo()->setXVelocity((480-y)/2, 1);
	}
	else if( e.type == SDL_KEYDOWN){
		//Mitä painettiin?
		switch( e.key.keysym.sym ){
			case SDLK_UP:
				maailma->getPelihahmo()->setYVelocity(200,-1);
			break;
			case SDLK_DOWN:
				maailma->getPelihahmo()->setYVelocity(200, 1);
			break;
			case SDLK_LEFT:
				maailma->getPelihahmo()->setXVelocity(200,-1);
			break;
			case SDLK_RIGHT:
				maailma->getPelihahmo()->setXVelocity(200, 1);			
			break;
			case SDLK_k:
				printf("kaupunkiin");
				pelitila->setTila(pelitila->kaupungissa);
			break;
		}

	}
	if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym ){
			case SDLK_UP:
				maailma->getPelihahmo()->setYVelocity(0,-1);
			break;
			case SDLK_DOWN:
				maailma->getPelihahmo()->setYVelocity(0, 1);
			break;
			case SDLK_LEFT:
				maailma->getPelihahmo()->setXVelocity(0,-1);
			break;
			case SDLK_RIGHT:
				maailma->getPelihahmo()->setXVelocity(0, 1);					
			break;
		}
	}

	//kaupungin avaus
	/*if( e.type == SDLK_k )
	{
		printf("kaupunkiin");
		kaupunki->lataaKuvat();
	}*/
}

int Pelimoottori::start()
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
		//Load media
		if( !mediaLoader->loadMedia(gRenderer) )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
			maailma->createStartingEnemys();
			mainLoop();
		}
	}
	//Sulje
	close();
	return 0;
}

void Pelimoottori::mainLoop(){
	quit = false;
		while( !quit )
		{
			//Tarkkaile näppäimiä
			if(pelitila->getTila() == pelitila->maailmassa){
				while( SDL_PollEvent( &e ) != 0 )
				{
					handleEvent();
				}
				maailma->render();
				maailma->move(FRAMETIMESTEP);
			}
			//Päivitä ruutu
			
			if(pelitila->getTila() == pelitila->kaupungissa){
				kaupunki->lataaKuvat();
			}
			SDL_RenderPresent( gRenderer );
			}
}

