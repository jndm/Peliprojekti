#include "MediaLoader.h"

MediaLoader::MediaLoader(Maailma* m, GUI* g){
	maailma = m;
	gui = g;
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
	//Lataa nopeudensäädinpohja
	if( !ssbTeksture.loadFromFile( "Images/GUI/SpeedSetterTriagle.png", gRenderer ) )
	{
		printf( "Failed to load speedsetter texture!\n" );
		success = false;
	}
	else{
		gui->setSpeedSetterBarTeksture(ssbTeksture);
	}
	//Lataa nopeudensäätönappula
	if( !ssButton.loadFromFile( "Images/GUI/SpeedSetterButton.png", gRenderer ) )
	{
		printf( "Failed to load speedsetterbutton texture!\n" );
		success = false;
	}
	else{
		gui->setSpeedSetterButtonTeksture(ssButton);
	}
	return success;
}