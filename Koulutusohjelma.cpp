#include "Koulutusohjelma.h"
#include "Opettaja.h"
#include "Opiskelija.h"
#include <vector>
#include <iostream>
#include <string>

//rakentajat ja purkaja
Koulutusohjelma::Koulutusohjelma() : nimi_(), opiskelijat_(), opettajat_()
{
}

Koulutusohjelma::Koulutusohjelma(std::string nimi) : nimi_(nimi)
{
}

Koulutusohjelma::~Koulutusohjelma()
{
}

//getterit

std::string Koulutusohjelma::annaNimi() const
{
	return nimi_;
}

std::vector <Opettaja> Koulutusohjelma::annaOpettajat() const
{
	return opettajat_;
}

std::vector <Opiskelija> Koulutusohjelma::annaOpiskelijat() const
{
	return opiskelijat_;
}

//setterit

void Koulutusohjelma::asetaNimi(std::string nimi)
{
	nimi_ = nimi;
}

void Koulutusohjelma::pushOpettajat(Opettaja ope)
{
	opettajat_.push_back(ope);
}

void Koulutusohjelma::pushOpiskelijat(Opiskelija oppi)
{
	opiskelijat_.push_back(oppi);
}

//rutiinit

void Koulutusohjelma::lisaaOpiskelija()
{
	Opiskelija Opis;
	std::cout << std::endl;
	Opis.kysyTiedot();
	std::cout << std::endl;
	opiskelijat_.push_back(Opis);
}

void Koulutusohjelma::lisaaOpettaja()
{
	Opettaja Ope;
	std::cout << std::endl;
	Ope.kysyTiedot();
	std::cout << std::endl;
	opettajat_.push_back(Ope);
}

void Koulutusohjelma::tulostaOpettajat() const
{
	std::cout << std::endl << "Opettajat:\n";
	for (int i = 0; i < opettajat_.size(); i++)
	{
		std::cout << std::endl;
		opettajat_[i].tulosta();
	}
	std::cout << std::endl << std::endl;
}

void Koulutusohjelma::tulostaOpiskelijat() const
{
	std::cout << std::endl << "Opiskelijat:\n";
	for (int i = 0; i < opiskelijat_.size(); i++)
	{
		std::cout << std::endl;
		opiskelijat_[i].tulosta();
	}
	std::cout << std::endl << std::endl;
}

void Koulutusohjelma::poistaOpettaja(int tunnus)
{
	opettajat_.erase(opettajat_.begin()+tunnus);
}

void Koulutusohjelma::poistaOpiskelija(int opiskelijanumero)
{
	opiskelijat_.erase(opiskelijat_.begin() + opiskelijanumero);
}

void Koulutusohjelma::paivitaOpettaja(int tunnus)
{
	opettajat_[tunnus].kysyTiedot();
}

void Koulutusohjelma::paivitaOpiskelija(int opiskelijanumero)
{
	opiskelijat_[opiskelijanumero].kysyTiedot();
}
