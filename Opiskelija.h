#pragma once
#include "Henkilo.h"
#include <string>
class Opiskelija :
	public Henkilo
{
public:
	Opiskelija();
	Opiskelija(std::string etunimi, std::string sukunimi, std::string osoite, std::string puhelinnumero, std::string opiskelijanumero);
	Opiskelija(const Opiskelija& alkup);
	~Opiskelija();

	Opiskelija& operator= (const Opiskelija& alkup); // sijoitusoperaattori

	std::string annaOpiskelijanumero() const;

	void asetaOpiskelijanumero(std::string opiskelijanumero);

	void kysyTiedot();
	void tulosta() const;

private:
	std::string opiskelijanumero_;
};

