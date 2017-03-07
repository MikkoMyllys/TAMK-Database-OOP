#include "Sovellus.h"
#include "Koulu.h"
#include <iostream>

Sovellus::Sovellus()
{
}

Sovellus::~Sovellus()
{
}

void Sovellus::aja() const
{
	Koulu koulu;

	while (true)
	{	
		std::string input = tulostaValikko();
		system("CLS");

		if (input == "1")
		{
			koulu.lisaaKoulutusohjelma();
		}
		else if (input == "2")
		{
			koulu.tulostaKoulutusohjelmat();
		}
		else if (input == "3")
		{
			koulu.tulostaKoulutusohjelmienMaara();
		}
		else if (input == "4")
		{
			koulu.lisaaKoulutusohjelmaanOpettaja();
		}
		else if (input == "5")
		{
			koulu.tulostaKoulutusohjelmanOpettajat();
		}
		else if (input == "6")
		{
			koulu.lisaaKoulutusohjelmaanOpiskelija();
		}
		else if (input == "7")
		{
			koulu.tulostaKoulutusohjelmanOpiskelijat();
		}
		else if (input == "8")
		{
			koulu.poistaKoulutusohjelma();
		}
		else if (input == "9")
		{
			try
			{
				koulu.poistaOpettaja();
			}
			catch (std::exception& error)
			{
				std::cerr << error.what() << std::endl;
				system("pause");
			}
			catch (...)
			{
				std::cerr << "\nIlmaantui virhe.\n" << std::endl;
				system("pause");
			}
		}
		else if (input == "10")
		{
			try
			{
				koulu.poistaOpiskelija();
			}
			catch (std::exception& error)
			{
				std::cerr << error.what() << std::endl;
				system("pause");
			}
			catch (...)
			{
				std::cerr << "\nIlmaantui virhe.\n" << std::endl;
				system("pause");
			}
		}
		else if (input == "11")
		{
			try
			{
				koulu.paivitaKoulutusohjelmanNimi();
			}
			catch (std::exception& error)
			{
				std::cerr << error.what() << std::endl;
				system("pause");
			}
			catch (...)
			{
				std::cerr << "\nIlmaantui virhe.\n" << std::endl;
				system("pause");
			}
		}
		else if (input == "12")
		{
			try
			{
				koulu.paivitaOpettaja();
			}
			catch (std::exception& error)
			{
				std::cerr << error.what() << std::endl;
				system("pause");
			}
			catch (...)
			{
				std::cerr << "\nIlmaantui virhe.\n" << std::endl;
				system("pause");
			}
		}
		else if (input == "13")
		{
			try
			{
				koulu.paivitaOpiskelija();
			}
			catch (std::exception& error)
			{
				std::cerr << error.what() << std::endl;
				system("pause");
			}
			catch (...)
			{
				std::cerr << "\nIlmaantui virhe.\n" << std::endl;
				system("pause");
			}
		}
		else if (input == "14")
		{
			koulu.lueTiedot();
		}
		else if (input == "15")
		{
			koulu.tallennaTiedot();
		}
		else if (input == "0")
		{
			system("CLS");
			std::cout << std::endl << "Ohjelma sulkeutuu." << std::endl << std::endl;
			break;
		}
		else
		{
			std::cout << std::endl << "Syote on virheellinen, yrita uudelleen." << std::endl << std::endl;
			system("pause");
		}
	}
}

std::string Sovellus::tulostaValikko() const
{
	std::string input;
	system("CLS");
	std::cout << "1) Lisaa koulutusohjelma" << std::endl;
	std::cout << "2) Tulosta koulutusohjelmien nimet" << std::endl;
	std::cout << "3) Tulosta koulutusohjelmien maara" << std::endl;
	std::cout << "4) Lisaa koulutusohjelmaan opettaja" << std::endl;
	std::cout << "5) Tulosta koulutusohjelman opettajat" << std::endl;
	std::cout << "6) Lisaa koulutusohjelmaan opiskelija" << std::endl;
	std::cout << "7) Tulosta koulutusohjelman opiskelijat" << std::endl;
	std::cout << "8) Poista koulutusohjelma" << std::endl;
	std::cout << "9) Poista opettaja" << std::endl;
	std::cout << "10) Poista opiskelija" << std::endl;
	std::cout << "11) Paivita koulutusohjelman nimi" << std::endl;
	std::cout << "12) Paivita opettajan tiedot" << std::endl;
	std::cout << "13) Paivita opiskelijan tiedot" << std::endl;
	std::cout << "14) Lue tiedot" << std::endl;
	std::cout << "15) Tallenna tiedot" << std::endl;
	std::cout << "0) Lopeta" << std::endl;

	std::cout << std::endl << "Valintasi: ";
	std::getline(std::cin, input);

	return input;
}
