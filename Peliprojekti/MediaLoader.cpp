#include "MediaLoader.h"

MediaLoader::MediaLoader(Maailma* m, GUI* g, Kaupunki* k){
	maailma = m;
	gui = g;
	kaupunki = k;
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
	//Load enemy
	if( !enemyText.loadFromFile( "Images/Characters/Vihollinen.png", gRenderer ) )
	{
		printf( "Failed to load enemy texture!\n" );
		success = false;
	}
	else{
		maailma->setEnemyTexture(enemyText);
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

	//Lataa Kaupungin tausta
	if(!kyla_kuva.loadFromFile("Images/Background/Kaupunki.bmp", gRenderer) )
	{
		printf( "Failed to load kaupunki texture!\n" );
		success = false;
	}else{
		kaupunki->setTaustaTexture(kyla_kuva);
	}
	//lataa Asepaja kylään
	if(!taloAse_kuva.loadFromFile("Images/Houses/talo.bmp", gRenderer) )
	{
		printf( "Failed to load asepaja texture!\n" );
		success = false;
	}else{
		kaupunki->setAsepajaTexture(taloAse_kuva);
	}
	//lataa Telakka kylään
	if(!taloTela_kuva.loadFromFile("Images/Houses/talo.bmp", gRenderer) )
	{
		printf( "Failed to load telakka texture!\n" );
		success = false;
	}else{
		kaupunki->setTelakkaTexture(taloTela_kuva);
	}
	//lataa Rautapaja kylään
	if(!taloRau_kuva.loadFromFile("Images/Houses/rautaPaja.png", gRenderer) )
	{
		printf( "Failed to load rautapaja texture!\n" );
		success = false;
	}else{
		kaupunki->setRautapajaTexture(taloRau_kuva);
	}
	//lataa Taverna kylään
	if(!taloTave_kuva.loadFromFile("Images/Houses/talo.bmp", gRenderer) )
	{
		printf( "Failed to load taverna texture!\n" );
		success = false;
	}else{
		kaupunki->setTavernaTexture(taloTave_kuva);
	}



	return success;
}