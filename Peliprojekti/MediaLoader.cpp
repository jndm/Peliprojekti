#include "MediaLoader.h"

MediaLoader::MediaLoader(Maailma* m){
	maailma = m;
}

bool MediaLoader::loadMedia(SDL_Renderer* gRenderer)
{
	//Loading success flag
	bool success = true;

	//Load pelihahmo texture
	if( !pelihahmoText.loadFromFile( "Images/Characters/Pelihahmo.png", gRenderer ) )
	{
		printf( "Failed to load player texture!\n" );
		success = false;
	}
	else{
		maailma->getPelihahmo()->setTekstuuri(pelihahmoText);
	}

	//Load background texture
	if( !taustaText.loadFromFile( "Images/Background/Meri.png", gRenderer ) )
	{
		printf( "Failed to load background texture!\n" );
		success = false;
	}
	else{
		maailma->setTaustaTexture(taustaText);
	}
	return success;
}