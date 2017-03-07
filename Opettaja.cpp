#include "Opettaja.h"
#include <iostream>
#include <string>
#include <algorithm>

//rakentaja ja purkaja
Opettaja::Opettaja() : Tyontekija(), opetusala_()
{
}

Opettaja::Opettaja(std::string etunimi, std::string sukunimi, std::string osoite, std::string puhelinnumero, std::string tunnus, std::string palkka, std::string opetusala) : Tyontekija(etunimi, sukunimi, osoite, puhelinnumero, tunnus, palkka), opetusala_(opetusala)
{
}

Opettaja::Opettaja(const Opettaja& alkup) : Tyontekija(alkup), opetusala_(alkup.opetusala_)
{
}

Opettaja::~Opettaja()
{
}

Opettaja& Opettaja::operator= (const Opettaja& alkup) // sijoitusoperaattori
{
	if (this != &alkup) // tarkistetaan ettei sijoiteta itseensä
	{
		Tyontekija::operator=(alkup); // kutsutaan kantaluokan sijoitusoperaattoria
		opetusala_ = alkup.opetusala_;
	}
	return *this;
}

//getterit
std::string Opettaja::annaOpetusala() const
{
	return opetusala_;
}


//setterit
void Opettaja::asetaOpetusala(std::string opetusala)
{
	opetusala_ = opetusala;
}


//rutiinit
void Opettaja::kysyTiedot()
{
	Tyontekija::kysyTiedot();
	bool syote_tyhja = true;
	while (syote_tyhja)
	{
		std::cout << "Anna opetusala: ";
		std::getline(std::cin, opetusala_);
		syote_tyhja = std::all_of(opetusala_.begin(), opetusala_.end(), isspace);
		if (syote_tyhja)
		{
			std::cout << "Syote ei voi olla tyhja." << std::endl;
		}
	}
}

void Opettaja::tulosta() const
{
	std::cout << opetusala_ << " ";
	Tyontekija::tulosta();
}