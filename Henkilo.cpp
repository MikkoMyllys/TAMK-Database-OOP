#include "Henkilo.h"
#include <iostream>
#include <string>
#include <algorithm>

//rakentajat ja purkaja
Henkilo::Henkilo() : etunimi_(), sukunimi_(), osoite_(), puhelinnumero_()
{
}

Henkilo::Henkilo(std::string etunimi, std::string sukunimi, std::string osoite, std::string puhelinnumero) : etunimi_(etunimi), sukunimi_(sukunimi), osoite_(osoite), puhelinnumero_(puhelinnumero)
{
}

Henkilo::Henkilo(const Henkilo& alkup) : etunimi_(alkup.etunimi_), sukunimi_(alkup.sukunimi_), osoite_(alkup.osoite_), puhelinnumero_(alkup.puhelinnumero_)
{
}

Henkilo::~Henkilo()
{
}

Henkilo& Henkilo::operator= (const Henkilo& alkup) // sijoitusoperaattori
{
	if (this != &alkup) // tarkistetaan ettei sijoiteta itseensä
	{
		etunimi_ = alkup.etunimi_;
		sukunimi_ = alkup.sukunimi_;
		osoite_ = alkup.osoite_;
		puhelinnumero_ = alkup.puhelinnumero_;
	}
	return *this;
}

//getterit

std::string Henkilo::annaEtunimi() const
{
	return etunimi_;
}

std::string Henkilo::annaSukunimi() const
{
	return sukunimi_;
}

std::string Henkilo::annaOsoite() const
{
	return osoite_;
}

std::string Henkilo::annaPuhelinnumero() const
{
	return puhelinnumero_;
}

//setterit

void Henkilo::asetaEtunimi(std::string etunimi)
{
	etunimi_ = etunimi;
}

void Henkilo::asetaSukunimi(std::string sukunimi)
{
	sukunimi_ = sukunimi;
}

void Henkilo::asetaOsoite(std::string osoite)
{
	osoite_ = osoite;
}

void Henkilo::asetaPuhelinnumero(std::string puhelinnumero)
{
	puhelinnumero_ = puhelinnumero;
}

//rutiinit

void Henkilo::kysyTiedot()
{
	bool syote_tyhja = true;
	while (syote_tyhja)
	{
		std::cout << "Anna etunimi: ";
		std::getline(std::cin, etunimi_);
		syote_tyhja = std::all_of(etunimi_.begin(), etunimi_.end(), isspace);
		if (syote_tyhja)
		{
			std::cout << "Syote ei voi olla tyhja." << std::endl;
		}
	}
	syote_tyhja = true;
	while (syote_tyhja)
	{
		std::cout << "Anna sukunimi: ";
		std::getline(std::cin, sukunimi_);
		syote_tyhja = std::all_of(sukunimi_.begin(), sukunimi_.end(), isspace);
		if (syote_tyhja)
		{
			std::cout << "Syote ei voi olla tyhja." << std::endl;
		}
	}
	syote_tyhja = true;
	while (syote_tyhja)
	{
		std::cout << "Anna osoite: ";
		std::getline(std::cin, osoite_);
		syote_tyhja = std::all_of(osoite_.begin(), osoite_.end(), isspace);
		if (syote_tyhja)
		{
			std::cout << "Syote ei voi olla tyhja." << std::endl;
		}
	}
	syote_tyhja = true;
	while (syote_tyhja)
	{
		std::cout << "Anna puhelinnumero: ";
		std::getline(std::cin, puhelinnumero_);
		syote_tyhja = std::all_of(puhelinnumero_.begin(), puhelinnumero_.end(), isspace);
		if (syote_tyhja)
		{
			std::cout << "Syote ei voi olla tyhja." << std::endl;
		}
	}
}

void Henkilo::tulosta() const
{
	std::cout << etunimi_ << " " << sukunimi_ << " " << osoite_ << " " << puhelinnumero_ << " ";
}