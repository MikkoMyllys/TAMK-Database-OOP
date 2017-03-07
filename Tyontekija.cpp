#include "Tyontekija.h"
#include <iostream>
#include <algorithm>


//rakentaja ja purkaja
Tyontekija::Tyontekija() : Henkilo(), tunnus_(), palkka_()
{
}

Tyontekija::Tyontekija(std::string etunimi, std::string sukunimi, std::string osoite, std::string puhelinnumero, std::string tunnus, std::string palkka) : Henkilo(etunimi, sukunimi, osoite, puhelinnumero), tunnus_(tunnus), palkka_(palkka)
{
}

Tyontekija::Tyontekija(const Tyontekija& alkup) : Henkilo(alkup), tunnus_(alkup.tunnus_), palkka_(alkup.palkka_)
{
}

Tyontekija::~Tyontekija()
{
}

Tyontekija& Tyontekija::operator= (const Tyontekija& alkup) // sijoitusoperaattori
{
	if (this != &alkup) // tarkistetaan ettei sijoiteta itseensä
	{
		Henkilo::operator=(alkup); // kutsutaan kantaluokan sijoitusoperaattoria
		tunnus_ = alkup.tunnus_;
		palkka_ = alkup.palkka_;
	}
	return *this;
}

//getterit
std::string Tyontekija::annaPalkka() const
{
	return palkka_;
}

std::string Tyontekija::annaTunnus() const
{
	return tunnus_;
}

//setterit
void Tyontekija::asetaPalkka(std::string palkka)
{
	palkka_ = palkka;
}

void Tyontekija::asetaTunnus(std::string tunnus)
{
	tunnus_ = tunnus;
}

//rutiinit
void Tyontekija::kysyTiedot()
{
	Henkilo::kysyTiedot();
	bool syote_tyhja = true;
	while (syote_tyhja)
	{
		std::cout << "Anna tunnus: ";
		std::getline(std::cin, tunnus_);
		syote_tyhja = std::all_of(tunnus_.begin(), tunnus_.end(), isspace);
		if (syote_tyhja)
		{
			std::cout << "Syote ei voi olla tyhja." << std::endl;
		}
	}
	syote_tyhja = true;
	while (syote_tyhja)
	{
		std::cout << "Anna palkka: ";
		std::getline(std::cin, palkka_);
		syote_tyhja = std::all_of(palkka_.begin(), palkka_.end(), isspace);
		if (syote_tyhja)
		{
			std::cout << "Syote ei voi olla tyhja." << std::endl;
		}
	}
}

void Tyontekija::tulosta() const
{
	std::cout << tunnus_ << " " << palkka_ << " ";
	Henkilo::tulosta();
}
