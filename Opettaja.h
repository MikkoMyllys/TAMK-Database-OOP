#pragma once
#include "Tyontekija.h"
#include <string>
class Opettaja :
	public Tyontekija
{
public:
	Opettaja();
	Opettaja(std::string etunimi, std::string sukunimi, std::string osoite, std::string puhelinnumero, std::string tunnus, std::string palkka, std::string opetusala);
	Opettaja(const Opettaja& alkup);
	~Opettaja();

	Opettaja& operator= (const Opettaja& alkup);

	std::string annaOpetusala() const;

	void asetaOpetusala(std::string opetusala);

	void kysyTiedot();
	void tulosta() const;
private:
	std::string opetusala_;
};

