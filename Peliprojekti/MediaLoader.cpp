#include "MediaLoader.h"

MediaLoader::MediaLoader(Maailma* m, GUI* g, MainMenu* mm){
	maailma = m;
	gui = g;
	mainmenu = mm;
}

bool MediaLoader::loadMedia(SDL_Renderer* gRenderer, int state)
{
	//Loading success flag
	bool success = true;

	switch(state){
		case 0:
			if( !mainmenuBtext.loadFromFile( "Images/MainMenu/Buttons.png", gRenderer ) )
			{
				printf( "Failed to load mainmenu textures!\n" );
				success = false;
			}
			else{
				mainmenu->setButtonTextures(mainmenuBtext);
			}
			if( !mainmenuTitletext.loadFromFile( "Images/MainMenu/Title.png", gRenderer ) )
			{
				printf( "Failed to load mainmenu textures!\n" );
				success = false;
			}
			else{
				mainmenu->setTitleTexture(mainmenuTitletext);
			}
			break;
		case 1:
			//Load pelihahmo texture
			if( !pelihahmoText.loadFromFile( "Images/Characters/Pelihahmo.png", gRenderer ) )
			{
				printf( "Failed to load player texture!\n" );
				success = false;
			}
			else{
				maailma->getPelihahmo()->setCharacterTexture(pelihahmoText);
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
			//Lataa vihollinen
			if( !enemyText.loadFromFile( "Images/Characters/Vihollinen.png", gRenderer ) )
			{
				printf( "Failed to load enemy texture!\n" );
				success = false;
			}
			else{
				maailma->setEnemyTexture(enemyText);
			}

			//Lataa enemyhealthbar
			if( !enemyHealthBarText.loadFromFile( "Images/Characters/Healthbar.png", gRenderer ) )
			{
				printf( "Failed to load enemy texture!\n" );
				success = false;
			}
			else{
				maailma->setEnemyHealthBarTexture(enemyHealthBarText);
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
			//Lataa tykinkuulan spritesheet
			if( !cannonballText.loadFromFile( "Images/Cannonball/cannonball.png", gRenderer ) )
			{
				printf( "Failed to load cannonball -sheet texture!\n" );
				success = false;
			}
			else{
				maailma->getPelihahmo()->setCannonballTexture(cannonballText);
			}
			//Lataa räjähdyksen spritesheet
			if( !explosionText.loadFromFile( "Images/Background/Rajahdys.png", gRenderer ) )
			{
				printf( "Failed to load cannonball -sheet texture!\n" );
				success = false;
			}
			else{
				maailma->setExplosionTexture(explosionText);
			}
	}

	return success;
}