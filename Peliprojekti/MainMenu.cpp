#include "MainMenu.h"
#include "Pelimoottori.h"

MainMenu::MainMenu(Pelimoottori* pelimoottori){
	SCREEN_WIDTH = pelimoottori->getSCREENWIDTH();
	SCREEN_HEIGHT = pelimoottori->getSCREENHEIGHT();
}

void MainMenu::setTitleTexture(Tekstuurit titletext){
	titletexture = titletext;
}

void MainMenu::setButtonTextures(Tekstuurit btextures){
	mainmenutext = btextures;
	startButton.x = 0;
	startButton.y = 0;
	startButton.w = 256;
	startButton.h = 68;
	quitButton.x = 0;
	quitButton.y = 69;
	quitButton.w = 256;
	quitButton.h = 68;
}

void MainMenu::render(){
	titletexture.render(SCREEN_WIDTH/2-titletexture.getTextureWidth()/2, 20);
	mainmenutext.render(SCREEN_WIDTH/2-startButton.w/2, SCREEN_HEIGHT/3-startButton.h/2, &startButton);
	mainmenutext.render(SCREEN_WIDTH/2-quitButton.w/2, SCREEN_HEIGHT/2-quitButton.h/2, &quitButton);
}

bool MainMenu::checkIfHitStart(int mx, int my){
        bool inside = true;

        if( mx < SCREEN_WIDTH/2-startButton.w/2 ){ inside = false; }
        else if( mx > SCREEN_WIDTH/2-startButton.w/2 + startButton.w ){ inside = false; }
        else if( my < SCREEN_HEIGHT/3-startButton.h/2 ){ inside = false; }
        else if( my > SCREEN_HEIGHT/3-startButton.h/2 + startButton.h ){ inside = false; }

		return inside;
}

bool MainMenu::checkIfHitQuit(int mx, int my){
        bool inside = true;

        if( mx < SCREEN_WIDTH/2-quitButton.w/2 ){ inside = false; }
        else if( mx > SCREEN_WIDTH/2-quitButton.w/2 + quitButton.w ){ inside = false; }
        else if( my < SCREEN_HEIGHT/2-quitButton.h/2 ){ inside = false; }
        else if( my > SCREEN_HEIGHT/2-quitButton.h/2 + quitButton.h ){ inside = false; }

		return inside;
}