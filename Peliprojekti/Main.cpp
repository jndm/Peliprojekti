#include "Main.h"
#include "Pelimoottori.h"
int main( int argc, char* args[] )
{
	Pelimoottori* pelimoottori = new Pelimoottori();
	pelimoottori->start();
	delete pelimoottori;
	return 0;
}