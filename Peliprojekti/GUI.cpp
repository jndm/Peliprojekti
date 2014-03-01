#include "GUI.h"

GUI::GUI(void){
	ssButtonX = 0;
	ssButtonY = 0;
}

void GUI::render(int cameraX, int cameraY){
	speedSetterBar.render(0, 0);
	speedSetterButton.render(ssButtonX, ssButtonY);
}

void GUI::setSpeedSetterBarTeksture(Tekstuurit ssb){
	speedSetterBar = ssb;

	//Luodaan ympärille neliö hiiren klikkauksia varten
	speedSetterBarArea.x = 0;
	speedSetterBarArea.y = 0;
	speedSetterBarArea.w = ssb.getTextureWidth();
	speedSetterBarArea.h = ssb.getTextureHeight();
}
void GUI::setSpeedSetterButtonTeksture(Tekstuurit ssbut){
	speedSetterButton = ssbut;
}

void GUI::moveSpeedBarButton(int my){
	ssButtonY = my;
}

bool GUI::checkIfHitSideBar(int mx, int my){
        bool inside = true;

        if( mx < speedSetterBarArea.x )
        {
            inside = false;
        }

        else if( mx > speedSetterBarArea.x + speedSetterBarArea.w )
        {
            inside = false;
        }

        else if( my < speedSetterBarArea.y )
        {
            inside = false;
        }

        else if( my > speedSetterBarArea.y + speedSetterBarArea.h )
        {
            inside = false;
        }

		return inside;
}