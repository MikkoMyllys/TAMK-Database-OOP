#pragma once
#include <string>
#include <vector>
#include "Koulutusohjelma.h"

class Koulu
{
public:
	Koulu();
	Koulu(std::string nimi);
	~Koulu();

	void asetaNimi(std::string nimi);
	std::string annaNimi();
	
	void lisaaKoulutusohjelma(); //valinta 1
	void tulostaKoulutusohjelmat() const; // valinta 2
	void tulostaKoulutusohjelmienMaara() const; // valinta 3
	void lisaaKoulutusohjelmaanOpettaja(); // valinta 4
	void tulostaKoulutusohjelmanOpettajat() const; // valinta 5
	void lisaaKoulutusohjelmaanOpiskelija(); // valinta 6
	void tulostaKoulutusohjelmanOpiskelijat() const; // valinta 7
	void poistaKoulutusohjelma(); //valinta 8
	void poistaOpettaja(); //valinta 9
	void poistaOpiskelija(); //valinta 10
	void paivitaKoulutusohjelmanNimi(); //valinta 11
	void paivitaOpettaja(); //valinta 12
	void paivitaOpiskelija(); //valinta 13
	void lueTiedot(); //valinta 14
	void tallennaTiedot(); //valinta 15

private:
	std::string nimi_;
	std::vector <Koulutusohjelma> koulutusohjelmat_;
	int etsiKoulutusohjelma() const; // apumetodi, joka palauttaa -1 jos ohjelmaa ei löydy, muutoin indeksinumeron
	int etsiKoulutusohjelmaEiSyotetta(std::string koulutusohjelma) const; // apumetodi, joka palauttaa -1 jos ohjelmaa ei löydy, muutoin indeksinumeron, ei tarvitse syötettä
	int etsiOpettaja(int ko_ohjelma) const;
	int etsiOpiskelija(int ko_ohjelma) const;
};

