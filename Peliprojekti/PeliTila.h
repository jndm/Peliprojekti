#pragma once
#ifndef PELITILA_H
#define PELITILA_H

class PeliTila
{
public:
	PeliTila(void);
	//~PeliTila(void);
	enum Tila{maailmassa, kaupungissa};
	void setTila(PeliTila::Tila tila);
	Tila getTila() const;
private:	
	Tila _tila;
};
#endif
