#ifndef TEKSTUURIT_H
#define TEKSTUURIT_H

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

class Tekstuurit{
public:
	bool loadFromFile(std::string path, SDL_Renderer* gRenderer);
	void render( int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE );
	void free();
	Tekstuurit(void);
	~Tekstuurit(void);
	int getTextureWidth(){ return textureWidth; }
	int getTextureHeight(){ return textureHeight; }


private:

	//Tekstuureja varten tarvittavat muuttujat
	int textureHeight, textureWidth;
	SDL_Texture* mTexture;
	SDL_Renderer* gRendererCopy;
};

#endif