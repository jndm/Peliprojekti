#include "Pelimoottori.h"

Pelimoottori::Pelimoottori(void){

	SCREEN_WIDTH = 640;
	SCREEN_HEIGHT = 480;
	LEVEL_WIDTH = 2048;
	LEVEL_HEIGHT = 2048;
	FRAMETIMESTEP = 1.f/60.f;
	pelihahmo = new Pelihahmo();

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
			gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
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

	//Alustetaan kamera
	camera.alusta(SCREEN_WIDTH, SCREEN_HEIGHT, pelihahmo);

	return success;
}

bool Pelimoottori::loadMedia()
{
	//Loading success flag
	bool success = true;

	//Load dot texture
	if( !nelio.loadFromFile( "Images/Characters/Pelihahmo.png", gRenderer ) )
	{
		printf( "Failed to load player texture!\n" );
		success = false;
	}
	else {
		pelihahmo->setTekstuuri(nelio);
	}

	//Load background texture
	if( !tausta.loadFromFile( "Images/Background/Meri.png", gRenderer ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
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
	delete pelihahmo;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void Pelimoottori::handleEvent(){
	if( e.type == SDL_QUIT ){
		quit = true;
	}
	else if( e.type == SDL_KEYDOWN){
		//Mitä painettiin?
		switch( e.key.keysym.sym ){
			case SDLK_UP:
				pelihahmo->setYVelocity(200,-1);
			break;
			case SDLK_DOWN:
				pelihahmo->setYVelocity(200, 1);
			break;
			case SDLK_LEFT:
				pelihahmo->setXVelocity(200,-1);
			break;
			case SDLK_RIGHT:
				pelihahmo->setXVelocity(200, 1);			
			break;
		}
	}
	if( e.type == SDL_KEYUP && e.key.repeat == 0 )
    {
        switch( e.key.keysym.sym ){
			case SDLK_UP:
				pelihahmo->setYVelocity(0,-1);
			break;
			case SDLK_DOWN:
				pelihahmo->setYVelocity(0, 1);
			break;
			case SDLK_LEFT:
				pelihahmo->setXVelocity(0,-1);
			break;
			case SDLK_RIGHT:
				pelihahmo->setXVelocity(0, 1);					
			break;
		}
	}
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
		if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{	
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
			while( SDL_PollEvent( &e ) != 0 )
			{
				handleEvent();
			}

			//Siirrä kamera
			camera.moveCamera(SCREEN_WIDTH, SCREEN_HEIGHT, LEVEL_WIDTH, LEVEL_HEIGHT);

			//Renderöi tausta
			tausta.render( 0, 0, &camera.getCamera() );

			//Renderöi pelihahmo
			pelihahmo->render( camera.getCameraX(), camera.getCameraY() );

			pelihahmo->move(FRAMETIMESTEP);
			//Päivitä ruutu
			SDL_RenderPresent( gRenderer );
		}
}

