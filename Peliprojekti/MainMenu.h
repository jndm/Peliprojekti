#ifndef MAINMENU_H
#define MAINMENU_H

#include "Tekstuurit.h"
class Pelimoottori;

class MainMenu{
public:
	MainMenu(Pelimoottori* pelimoottori);
	void setTitleTexture(Tekstuurit titletext);
	void setButtonTextures(Tekstuurit btextures);
	bool checkIfHitQuit(int mx, int my);
	bool checkIfHitStart(int mx, int my);
	void render();
private:
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	Tekstuurit titletexture;
	Tekstuurit mainmenutext;
	SDL_Rect startButton;
	SDL_Rect quitButton;
};
#endif