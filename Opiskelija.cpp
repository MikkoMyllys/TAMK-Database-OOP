#include "Opiskelija.h"
#include <iostream>
#include <algorithm>

//rakentaja ja purkaja
Opiskelija::Opiskelija() : Henkilo(), opiskelijanumero_()
{
}

Opiskelija::Opiskelija(std::string etunimi, std::string sukunimi, std::string osoite, std::string puhelinnumero, std::string opiskelijanumero) : Henkilo(etunimi, sukunimi, osoite, puhelinnumero), opiskelijanumero_(opiskelijanumero)
{
}

Opiskelija::Opiskelija(const Opiskelija& alkup) : Henkilo(alkup), opiskelijanumero_(alkup.opiskelijanumero_)
{
}

Opiskelija::~Opiskelija()
{
}

Opiskelija& Opiskelija::operator= (const Opiskelija& alkup) // sijoitusoperaattori
{
	if (this != &alkup) // tarkistetaan ettei sijoiteta itseensä
	{
		Henkilo::operator=(alkup); // kutsutaan kantaluokan sijoitusoperaattoria
		opiskelijanumero_ = alkup.opiskelijanumero_;
	}
	return *this;
}

//getterit
std::string Opiskelija::annaOpiskelijanumero() const
{
	return opiskelijanumero_;
}


//setterit
void Opiskelija::asetaOpiskelijanumero(std::string opiskelijanumero)
{
	opiskelijanumero_ = opiskelijanumero;
}


//rutiinit
void Opiskelija::kysyTiedot()
{
	Henkilo::kysyTiedot();
	bool syote_virhe = true;
	while (syote_virhe)
	{
		std::cout << "Anna opiskelijanumero: ";
		std::getline(std::cin, opiskelijanumero_);
		syote_virhe = std::all_of(opiskelijanumero_.begin(), opiskelijanumero_.end(), isspace);
		if (syote_virhe)
		{
			std::cout << "Syote ei voi olla tyhja." << std::endl;
		}
	}
}

void Opiskelija::tulosta() const
{
	std::cout << opiskelijanumero_ << " ";
	Henkilo::tulosta();
}