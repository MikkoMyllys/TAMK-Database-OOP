#pragma once
#include <string>
#include <vector>
#include "Opiskelija.h"
#include "Opettaja.h"

class Koulutusohjelma
{
public:
	Koulutusohjelma();
	Koulutusohjelma(std::string nimi);
	~Koulutusohjelma();

	std::string annaNimi() const;
	std::vector <Opettaja> annaOpettajat() const;
	std::vector <Opiskelija> annaOpiskelijat() const;

	void asetaNimi(std::string nimi);
	void pushOpettajat(Opettaja ope);
	void pushOpiskelijat(Opiskelija oppi);

	void lisaaOpettaja();
	void lisaaOpiskelija();
	void tulostaOpettajat() const;
	void tulostaOpiskelijat() const;
	void poistaOpettaja(int tunnus);
	void poistaOpiskelija(int opiskelijanumero);
	void paivitaOpettaja(int tunnus);
	void paivitaOpiskelija(int opiskelijanumero);

private:
	std::string nimi_;
	std::vector <Opiskelija> opiskelijat_;
	std::vector <Opettaja> opettajat_;
};

