#ifndef GUI_H
#define GUI_H

#include "Tekstuurit.h"
class GUI{
public:
	void render(int cameraX, int cameraY);
	void setSpeedSetterBarTeksture(Tekstuurit ssb);
	void setSpeedSetterButtonTeksture(Tekstuurit ssbut);
	void moveSpeedBarButton(int my);
	bool checkIfHitSideBar(int mx, int my);
	GUI(void);

private:
	int ssButtonX, ssButtonY;
	Tekstuurit speedSetterBar;
	Tekstuurit speedSetterButton;
	SDL_Rect speedSetterBarArea;
};
#endif