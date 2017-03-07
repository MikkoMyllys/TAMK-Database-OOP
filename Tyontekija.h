#pragma once
#include "Henkilo.h"
#include <string>
class Tyontekija :
	public Henkilo
{
public:
	Tyontekija();
	Tyontekija(std::string etunimi, std::string sukunimi, std::string osoite, std::string puhelinnumero, std::string tunnus, std::string palkka);
	Tyontekija(const Tyontekija& alkup);
	~Tyontekija();	

	Tyontekija& operator= (const Tyontekija& alkup);

	std::string annaPalkka() const;
	std::string annaTunnus() const;
	void asetaPalkka(std::string palkka); 
	void asetaTunnus(std::string tunnus);

	void kysyTiedot();
	void tulosta() const;

private:
	std::string tunnus_;
	std::string palkka_;
};

