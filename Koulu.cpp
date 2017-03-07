#include "Koulu.h"
#include "Koulutusohjelma.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <direct.h>

Koulu::Koulu() : nimi_(), koulutusohjelmat_()
{
}

Koulu::Koulu(std::string nimi) : nimi_(nimi), koulutusohjelmat_()
{
}

Koulu::~Koulu()
{
}

void Koulu::asetaNimi(std::string nimi)
{
	nimi_ = nimi;
}

std::string Koulu::annaNimi()
{
	return nimi_;
}

void Koulu::lisaaKoulutusohjelma() // valinta 1
{
	bool nimi_virhe = true;
	std::string ko_nimi;
	
	while (nimi_virhe)
	{
		std::cout << std::endl;
		std::cout << "Anna koulutusohjelman nimi: ";
		std::getline(std::cin, ko_nimi);
		nimi_virhe = std::all_of(ko_nimi.begin(), ko_nimi.end(), isspace); // tarkistetaan ettei syöte ole tyhjä tai sisällä vain välilyöntejä
		if (nimi_virhe)
		{
			std::cout << std::endl << "Syote ei voi olla tyhja." << std::endl << std::endl;
			system("pause");
		}
		else
		{
			for (int i = 0; i < koulutusohjelmat_.size(); i++)
			{
				if (koulutusohjelmat_[i].annaNimi() == ko_nimi)
				{
					std::cout << std::endl << "Annettu koulutusohjelma on jo olemassa." << std::endl << std::endl;
					nimi_virhe = true;
					system("pause");
				}
			}
		}
		system("CLS");
	}
	koulutusohjelmat_.push_back({ ko_nimi }); // käytetään koulutusohjelma param. rak.
}

void Koulu::tulostaKoulutusohjelmat() const // valinta 2
{
	std::cout << std::endl << "Koulutusohjelmat:\n";
	for (int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		std::cout << std::endl;
		std::cout << koulutusohjelmat_[i].annaNimi();
	}
	std::cout << std::endl << std::endl;
	system("pause");
}

void Koulu::tulostaKoulutusohjelmienMaara() const // valinta 3
{
	int maara = 0;
	std::cout << std::endl << "Koulutusohjelmien maara: ";
	for (int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		maara++;
	}
	std::cout << maara;
	std::cout << std::endl << std::endl;
	system("pause");
}

int Koulu::etsiKoulutusohjelma() const // apumetodi
{
	std::string koh_nimi;
	std::cout << "Anna koulutusohjelman nimi: ";
	std::getline(std::cin, koh_nimi);
	for (int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		if (koulutusohjelmat_[i].annaNimi() == koh_nimi)
		{
			return i; // palauttaa koulutusohjelman indeksin jos ohjelma löytyi
		}
	}
	return -1; // jos haettua koulutusohjelmaa ei löydy
}

int Koulu::etsiKoulutusohjelmaEiSyotetta(std::string koulutusohjelma) const // apumetodi
{
	for (int i = 0; i < koulutusohjelmat_.size(); i++)
	{
		if (koulutusohjelmat_[i].annaNimi() == koulutusohjelma)
		{
			return i; // palauttaa koulutusohjelman indeksin jos ohjelma löytyi
		}
	}
	return -1; // jos haettua koulutusohjelmaa ei löydy
}

void Koulu::lisaaKoulutusohjelmaanOpettaja() // valinta 4
{
	std::cout << std::endl;
	int ko_ohjelma = etsiKoulutusohjelma();
	if (ko_ohjelma != -1)
	{
		koulutusohjelmat_[ko_ohjelma].lisaaOpettaja();
	}	
	else
	{
		std::cout << std::endl << "Haettua koulutusohjelmaa ei loytynyt." << std::endl << std::endl;
		system("pause");
	}
}

void Koulu::tulostaKoulutusohjelmanOpettajat() const // valinta 5
{
	std::cout << std::endl;
	int ko_ohjelma = etsiKoulutusohjelma();
	if (ko_ohjelma != -1)
	{
		koulutusohjelmat_[ko_ohjelma].tulostaOpettajat();
	}
	else
	{
		std::cout << std::endl << "Haettua koulutusohjelmaa ei loytynyt." << std::endl << std::endl;
	}
	system("pause");
}

void Koulu::lisaaKoulutusohjelmaanOpiskelija() // valinta 6
{
	std::cout << std::endl;
	int ko_ohjelma = etsiKoulutusohjelma();
	if (ko_ohjelma != -1)
	{
		koulutusohjelmat_[ko_ohjelma].lisaaOpiskelija();
	}
	else
	{
		std::cout << std::endl << "Haettua koulutusohjelmaa ei loytynyt." << std::endl << std::endl;
		system("pause");
	}
}

void Koulu::tulostaKoulutusohjelmanOpiskelijat() const // valinta 7
{
	std::cout << std::endl;
	int ko_ohjelma = etsiKoulutusohjelma();
	if (ko_ohjelma != -1)
	{
		koulutusohjelmat_[ko_ohjelma].tulostaOpiskelijat();
	}
	else
	{
		std::cout << std::endl << "Haettua koulutusohjelmaa ei loytynyt." << std::endl << std::endl;
	}
	system("pause");
}

void Koulu::poistaKoulutusohjelma() // valinta 8
{
	std::cout << std::endl;
	int ko_ohjelma = etsiKoulutusohjelma();
	if (ko_ohjelma != -1)
	{
		koulutusohjelmat_.erase(koulutusohjelmat_.begin()+ko_ohjelma);
		std::cout << std::endl << "Koulutusohjelma poistettu." << std::endl << std::endl;
		system("pause");
	}
	else
	{
		std::cout << std::endl << "Haettua koulutusohjelmaa ei loytynyt." << std::endl << std::endl;
		system("pause");
	}
}

void Koulu::poistaOpettaja() // valinta 9
{
	std::cout << std::endl;
	int ko_ohjelma = etsiKoulutusohjelma();
	if (ko_ohjelma != -1)
	{
		int tunnus = etsiOpettaja(ko_ohjelma);
		if (tunnus != -1)
		{
			koulutusohjelmat_[ko_ohjelma].poistaOpettaja(tunnus);
			std::cout << std::endl << "Opettaja poistettu." << std::endl << std::endl;
			system("pause");
		}
		else
		{
			std::cout << std::endl << "Haettua opettajaa ei loytynyt." << std::endl << std::endl;
			system("pause");
		}
	}
	else
	{
		std::cout << std::endl << "Haettua koulutusohjelmaa ei loytynyt." << std::endl << std::endl;
		system("pause");
	}
}

void Koulu::poistaOpiskelija() // valinta 10
{
	std::cout << std::endl;
	int ko_ohjelma = etsiKoulutusohjelma();
	if (ko_ohjelma != -1)
	{
		int opiskelijanumero = etsiOpiskelija(ko_ohjelma);
		if (opiskelijanumero != -1)
		{
			koulutusohjelmat_[ko_ohjelma].poistaOpiskelija(opiskelijanumero);
			std::cout << std::endl << "Opiskelija poistettu." << std::endl << std::endl;
			system("pause");
		}
		else
		{
			std::cout << std::endl << "Haettua opiskelijaa ei loytynyt." << std::endl << std::endl;
			system("pause");
		}
	}
	else
	{
		std::cout << std::endl << "Haettua koulutusohjelmaa ei loytynyt." << std::endl << std::endl;
		system("pause");
	}
}

int Koulu::etsiOpettaja(int ko_ohjelma) const try// apumetodi
{
	if (koulutusohjelmat_[ko_ohjelma].annaOpettajat().size() > 0)
	{
		std::string ope_tunnus;
		std::cout << std::endl;
		std::cout << "Anna opettajan tunnus: ";
		std::getline(std::cin, ope_tunnus);
		for (int i = 0; i < koulutusohjelmat_[ko_ohjelma].annaOpettajat().size(); i++)
		{
			if (koulutusohjelmat_[ko_ohjelma].annaOpettajat()[i].annaTunnus() == ope_tunnus)
			{
				return i; // palauttaa opettajan indeksin jos opettaja löytyi
			}
		}
		return -1; // jos haettua opettajaa ei löydy
	}
	else
	{
		throw std::out_of_range("\nKoulutusohjelmassa ei ole opettajia.\n");
	}
}
catch (...)
{
	throw;
}

int Koulu::etsiOpiskelija(int ko_ohjelma) const try// apumetodi
{
	if (koulutusohjelmat_[ko_ohjelma].annaOpiskelijat().size() > 0)
	{
		std::string opiskelijanumero;
		std::cout << std::endl;
		std::cout << "Anna opiskelijanumero: ";
		std::getline(std::cin, opiskelijanumero);
		for (int i = 0; i < koulutusohjelmat_[ko_ohjelma].annaOpiskelijat().size(); i++)
		{
			if (koulutusohjelmat_[ko_ohjelma].annaOpiskelijat()[i].annaOpiskelijanumero() == opiskelijanumero)
			{
				return i; // palauttaa opettajan indeksin jos opettaja löytyi
			}
		}
		return -1; // jos haettua opettajaa ei löydy
	}
	else
	{
		throw std::out_of_range("\nKoulutusohjelmassa ei ole opiskelijoita.\n");
	}
}
catch (...)
{
	throw;
}

void Koulu::paivitaKoulutusohjelmanNimi() // valinta 11
{
	std::cout << std::endl;
	std::string uusiNimi;
	int ko_ohjelma = etsiKoulutusohjelma();
	if (ko_ohjelma != -1)
	{
		std::cout << std::endl << "Anna koulutusohjelmalle uusi nimi: ";
		std::getline(std::cin, uusiNimi);
		koulutusohjelmat_[ko_ohjelma].asetaNimi(uusiNimi);
		std::cout << std::endl << "Koulutusohjelma on nimetty uudelleen." << std::endl << std::endl;
	}
	else
	{
		std::cout << std::endl << "Haettua koulutusohjelmaa ei loytynyt." << std::endl << std::endl;
	}
	system("pause");
}

void Koulu::paivitaOpettaja() // valinta 12
{
	std::cout << std::endl;
	int ko_ohjelma = etsiKoulutusohjelma();
	if (ko_ohjelma != -1)
	{
		int tunnus = etsiOpettaja(ko_ohjelma);
		if (tunnus != -1)
		{
			std::cout << std::endl << "---Uudet tiedot---" << std::endl;
			koulutusohjelmat_[ko_ohjelma].paivitaOpettaja(tunnus);
			std::cout << std::endl << "Opettajan tiedot paivitetty." << std::endl << std::endl;
			system("pause");
		}
		else
		{
			std::cout << std::endl << "Haettua opettajaa ei loytynyt." << std::endl << std::endl;
			system("pause");
		}
	}
	else
	{
		std::cout << std::endl << "Haettua koulutusohjelmaa ei loytynyt." << std::endl << std::endl;
		system("pause");
	}
}

void Koulu::paivitaOpiskelija() // valinta 13
{
	std::cout << std::endl;
	int ko_ohjelma = etsiKoulutusohjelma();
	if (ko_ohjelma != -1)
	{
		int opiskelijanumero = etsiOpiskelija(ko_ohjelma);
		if (opiskelijanumero != -1)
		{
			std::cout << std::endl << "---Uudet tiedot---" << std::endl;
			koulutusohjelmat_[ko_ohjelma].paivitaOpiskelija(opiskelijanumero);
			std::cout << std::endl << "Opiskelijan tiedot paivitetty." << std::endl << std::endl;
			system("pause");
		}
		else
		{
			std::cout << std::endl << "Haettua opiskelijaa ei loytynyt." << std::endl << std::endl;
			system("pause");
		}
	}
	else
	{
		std::cout << std::endl << "Haettua koulutusohjelmaa ei loytynyt." << std::endl << std::endl;
		system("pause");
	}
}

void Koulu::lueTiedot() // valinta 14
{
	koulutusohjelmat_.clear();  // tyhjennetään kaikki vektorit tietojen lukua varten
	std::ifstream luku_tied; // luodaan tiedosto-olio lukua varten
	std::string etunimi, sukunimi, osoite, puhelinnumero, opiskelijanumero, tunnus, opetusala, palkka, koulutusohjelma;
	int koulutusohjelma_indeksi = 0;
	bool virhe1 = false;
	bool virhe2 = false;

	luku_tied.open("opettajat.csv");
	if (luku_tied.is_open())
	{
		while (luku_tied.peek() != EOF) // luetaan tiedosto loppuu, End Of File
		{
			std::getline(luku_tied, koulutusohjelma, ';'); // luetaan apu-stringeihin
			std::getline(luku_tied, etunimi, ';'); 
			std::getline(luku_tied, opetusala, ';');
			std::getline(luku_tied, osoite, ';');
			std::getline(luku_tied, palkka, ';');
			std::getline(luku_tied, puhelinnumero, ';');
			std::getline(luku_tied, sukunimi, ';');
			std::getline(luku_tied, tunnus, '\n');
			Opettaja apu_ope(etunimi, sukunimi, osoite, puhelinnumero, tunnus, palkka, opetusala); // luodaan opettaja-olio

			koulutusohjelma_indeksi = etsiKoulutusohjelmaEiSyotetta(koulutusohjelma);
			if (koulutusohjelma_indeksi != -1)
			{
				koulutusohjelmat_[koulutusohjelma_indeksi].pushOpettajat(apu_ope);
			}
			else
			{
				if (tunnus == "EI_OPETTAJIA") //jos ei löydy opettajia lisätään vain löydetty koulutusohjelma
				{
					Koulutusohjelma apu_ohj(koulutusohjelma);
					koulutusohjelmat_.push_back(apu_ohj);
				}
				else
				{
					Koulutusohjelma apu_ohj(koulutusohjelma);
					koulutusohjelmat_.push_back(apu_ohj);
					koulutusohjelmat_[koulutusohjelmat_.size() - 1].pushOpettajat(apu_ope);
				}

			}
		}
		luku_tied.close();
	}
	else
	{
		std::cout << "Tiedostoa ei voitu avata!\nopettajat.csv tiedosto puuttuu." << std::endl;
		virhe1 = true;
	}

	// seuraavaksi luetaan opiskelijoiden tiedot

	koulutusohjelma = ""; //tyhjennetään apumuuttuja
	luku_tied.open("opiskelijat.csv");
	if (luku_tied.is_open())
	{
		while (luku_tied.peek() != EOF) // luetaan tiedosto loppuu, End Of File
		{
			std::getline(luku_tied, koulutusohjelma, ';');
			std::getline(luku_tied, etunimi, ';'); // luetaan apu-stringeihin
			std::getline(luku_tied, opiskelijanumero, ';');
			std::getline(luku_tied, osoite, ';');
			std::getline(luku_tied, puhelinnumero, ';');
			std::getline(luku_tied, sukunimi, '\n');
			Opiskelija apu_oppi(etunimi, sukunimi, osoite, puhelinnumero, opiskelijanumero); // luodaan opiskelija-olio

			koulutusohjelma_indeksi = etsiKoulutusohjelmaEiSyotetta(koulutusohjelma);
			if (koulutusohjelma_indeksi != -1)
			{
				if (opiskelijanumero != "EI_OPISKELIJOITA") //lisätään opiskelijat jos niitä on
				{
					koulutusohjelmat_[koulutusohjelma_indeksi].pushOpiskelijat(apu_oppi);
				}
				
			}
			else
			{
				if (opiskelijanumero != "EI_OPISKELIJOITA") 
				{
					Koulutusohjelma apu_ohj(koulutusohjelma);
					koulutusohjelmat_.push_back(apu_ohj);
					koulutusohjelmat_[koulutusohjelmat_.size() - 1].pushOpiskelijat(apu_oppi);
				}
				else  //jos ei löydy opiskelijoita lisätään vain löydetty koulutusohjelma
				{
					Koulutusohjelma apu_ohj(koulutusohjelma);
					koulutusohjelmat_.push_back(apu_ohj);
				}
				
			}
		}
		luku_tied.close();
	}
	else
	{
		std::cout << "Tiedostoa ei voitu avata!\nopiskelijat.csv tiedosto puuttuu." << std::endl;
		virhe2 = true;
	}
	
	if (virhe1 == false && virhe2 == false)
	{
		std::cout << "Tiedot luettu." << std::endl << std::endl;	
	}
	system("pause");

}

void Koulu::tallennaTiedot() // valinta 15
{
	bool virhe1 = false;
	bool virhe2 = false;
	std::string polku = _getcwd(NULL, 0); // tulostetaan polku minne opettajat tallennetaan
	std::cout << "Oletuspolku: " << polku << std::endl;

	std::ofstream kirj_tied; // luodaan tiedosto-olio kirjoitusta varten
	kirj_tied.open("opettajat.csv");

	if (kirj_tied.is_open()) // tarkistetaan onko tallennustiedosto auki
	{
		for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) // kirjoitetaan opettajien tiedot tiedostoon, ';'-merkki toimii erottimena
		{
			for (unsigned int j = 0; j < koulutusohjelmat_[i].annaOpettajat().size(); j++)
			{
				kirj_tied << koulutusohjelmat_[i].annaNimi() << ';';
				kirj_tied << koulutusohjelmat_[i].annaOpettajat()[j].annaEtunimi() << ';';
				kirj_tied << koulutusohjelmat_[i].annaOpettajat()[j].annaOpetusala() << ';';
				kirj_tied << koulutusohjelmat_[i].annaOpettajat()[j].annaOsoite() << ';';
				kirj_tied << koulutusohjelmat_[i].annaOpettajat()[j].annaPalkka() << ';';
				kirj_tied << koulutusohjelmat_[i].annaOpettajat()[j].annaPuhelinnumero() << ';';
				kirj_tied << koulutusohjelmat_[i].annaOpettajat()[j].annaSukunimi() << ';';
				kirj_tied << koulutusohjelmat_[i].annaOpettajat()[j].annaTunnus() << '\n';
			}
			if (koulutusohjelmat_[i].annaOpettajat().size() == 0) // jos koulutusohjelma ei sisällä vielä opettajia
			{
				kirj_tied << koulutusohjelmat_[i].annaNimi() << "; ; ; ; ; ; ;EI_OPETTAJIA\n";
			}
		}
		kirj_tied.close();
	}
	else
	{
		std::cout << "Tiedostoa ei voitu avata!" << std::endl;
		virhe1 = true;
	}

	//seuraavaksi tallennetaan opiskelijoiden tiedot---------------------------------------------

	kirj_tied.open("opiskelijat.csv");

	if (kirj_tied.is_open()) // tarkistetaan onko tallennustiedosto auki
	{
		for (unsigned int i = 0; i < koulutusohjelmat_.size(); i++) // kirjoitetaan opiskelijoitten tiedot tiedostoon, ';'-merkki toimii erottimena
		{
			for (unsigned int j = 0; j < koulutusohjelmat_[i].annaOpiskelijat().size(); j++)
			{
				kirj_tied << koulutusohjelmat_[i].annaNimi() << ';';
				kirj_tied << koulutusohjelmat_[i].annaOpiskelijat()[j].annaEtunimi() << ';';
				kirj_tied << koulutusohjelmat_[i].annaOpiskelijat()[j].annaOpiskelijanumero() << ';';
				kirj_tied << koulutusohjelmat_[i].annaOpiskelijat()[j].annaOsoite() << ';';
				kirj_tied << koulutusohjelmat_[i].annaOpiskelijat()[j].annaPuhelinnumero() << ';';
				kirj_tied << koulutusohjelmat_[i].annaOpiskelijat()[j].annaSukunimi() << '\n';
			}
			if (koulutusohjelmat_[i].annaOpiskelijat().size() == 0) // jos koulutusohjelma ei sisällä vielä opiskelijoita
			{
				kirj_tied << koulutusohjelmat_[i].annaNimi() << "; ;EI_OPISKELIJOITA; ; ; \n";
			}
		}
		kirj_tied.close();
	}
	else
	{
		std::cout << "Tiedostoa ei voitu avata!" << std::endl;
		virhe2 = true;
	}

	if (virhe1 == false && virhe2 == false)
	{
		std::cout << std::endl << "Tiedot tallennettu." << std::endl << std::endl;	
	}
	system("pause");
}