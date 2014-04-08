#include "PeliTila.h"


PeliTila::PeliTila(void)
{
	Tila _tila = maailmassa;
}



void PeliTila::setTila(PeliTila::Tila tila)
{
	_tila = tila;
}

PeliTila::Tila PeliTila::getTila() const
{
	return _tila;
}