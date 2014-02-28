#include "Tekstuurit.h"

Tekstuurit::Tekstuurit(){
	textureHeight = 0;
	textureWidth = 0;
	mTexture = NULL;
}

Tekstuurit::~Tekstuurit(){

}

bool Tekstuurit::loadFromFile(std::string path, SDL_Renderer* gRenderer){
	//Get rid of preexisting texture
	free();

	gRendererCopy = gRenderer;
	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
	if( loadedSurface == NULL )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
	}
	else
	{
		//Color key, jolla voidaan m‰‰ritt‰‰ l‰pin‰kyv‰ v‰ri
		SDL_SetColorKey( loadedSurface, SDL_TRUE, SDL_MapRGB( loadedSurface->format, 0, 0xFF, 0xFF ) );

		//Luodaan tekstuuri kuvasta(surfacesta)
        newTexture = SDL_CreateTextureFromSurface( gRendererCopy, loadedSurface );
		if( newTexture == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
		}
		else
		{
			//Haetaan kuvan koko
			textureWidth = loadedSurface->w;
			textureHeight = loadedSurface->h;
		}

		//H‰vitet‰‰n kuvan lataukseen k‰ytetty surface
		SDL_FreeSurface( loadedSurface );
	}
	mTexture = newTexture;
	return mTexture != NULL;
}

void Tekstuurit::free()
{
	//Vapautetaan tekstuurin paikka, jos sellainen on
	if( mTexture != NULL )
	{
		SDL_DestroyTexture( mTexture );
		mTexture = NULL;
		textureWidth = 0;
		textureHeight = 0;
	}
}

void Tekstuurit::render( int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip )
{
	//Katsotaan renderˆinnin paikka ja koko
	SDL_Rect renderQuad = { x, y, textureWidth, textureHeight };

	//Mik‰li kuva on suurempi kuin ikkuna (taustakuva) rajataan sen koko ikkunaan sopivaksi
	//ja otetaan kuvasta palanen, joka osuu kameran alueelle
	if( clip != NULL )
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;

	}
	
	//Kopioidaan kuva renderiin, joka esitet‰‰n pelimoottorissa
	SDL_RenderCopyEx( gRendererCopy, mTexture, clip, &renderQuad, angle, center, flip );
}