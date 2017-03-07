#pragma once
#include <string>
class Henkilo
{
public:
	Henkilo();
	Henkilo(std::string etunimi, std::string sukunimi, std::string osoite, std::string puhelinnumero);
	Henkilo(const Henkilo& alkup);
	~Henkilo();

	Henkilo& operator= (const Henkilo& alkup); //sijoitusoperaattori

	std::string annaEtunimi() const;
	std::string annaSukunimi() const;
	std::string annaOsoite() const;
	std::string annaPuhelinnumero() const;

	void asetaEtunimi(std::string etunimi);
	void asetaSukunimi(std::string sukunimi);
	void asetaOsoite(std::string osoite);
	void asetaPuhelinnumero(std::string puhelinnumero);

	void kysyTiedot();
	void tulosta() const;

private:
	std::string etunimi_;
	std::string sukunimi_;
	std::string osoite_;
	std::string puhelinnumero_;
};

