#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool opakovat = true;

char znak[256];
int meziZnak[256];
int vyslednyZnak[256];

int stupen_sifrovani;

string typ_zapisu_sifri;

string outFile;

string inFile;

int main()
{
	while (opakovat)
	{
		fstream ASCI("ASCI.txt", ios::out);
		ASCI << "vypis ciselneho oznaceni vsech zakladnich ASCI znaku" << endl;
		for (int a = 0; a < 256; a++)
		{
			ASCI << a << "	" << char(a) << endl;
		}
		ASCI.close();
		opakovat = false;
		std::cout << "cilovy soubor pro textovou verzi" << endl;
		cin >> outFile;
		std::cout << "zadej stupen sifrovani" << endl;
		cin >> stupen_sifrovani;
		if (outFile == "anicka")
		{
			DEKODER:
			std::cout << "zadej soubor k desifraci - pokud neni ve slozce s programem musis zadat celou jeho adresu" << endl;
			cin >> inFile;
			inFile += ".txt";
			std::cout << "zadej stupen sifrovani" << endl;
			cin >> stupen_sifrovani;
			fstream InFile(inFile, ios::in);
			char pomocna;
			char data[256];
			int pomocna2;
			int meziData[256];
			int vystupniData[256];

			for (int a = 0; a < 256; a++)
			{
				data[a] = 123;
			}

			for (int a = 0; a < 256; a++)
			{
				InFile >> pomocna;
				if ((pomocna != 59))
				{
					data[a] = pomocna - 97;
				}
				else
				{
					a--;
				}
			}
			for (int a = 0; a < 256; a++)
			{
				meziData[a] = int(data[a]);
			}

			InFile.close();

			
			
			vystupniData[0] = meziData[0];
			for (int b = 0; b < stupen_sifrovani; b++)
			{
				for (int a = 0; a < 255; a++)
				{
					vystupniData[1+a] = meziData[1+a] + vystupniData[a];
				}
				for (int a = 0; a < 256; a++)
				{
					std::cout << vystupniData[a] << " ";
					if (a % 16 == 0)
					{
						std::cout << endl;
					}
				}
				for (int a = 0; a < 256; a++)
				{
					meziData[a] = vystupniData[a];
				}
			}

			
			for (int a = 0; a < 256; a++)
			{
				vystupniData[a] += 97;
			}
			std::cout << endl << endl;
			for (int a = 0; a < 256; a++)
			{
				std::cout << char(vystupniData[a]);
			}

			fstream memoryFile("desifracni_pamet.txt", ios::out);
			memoryFile << "Ahoj koukam ze si objevila muj cteni dekoder. To bych klidne prohlasil ze si zaslouzis"<< endl <<
						  "jeste jednu vyhro pokud ji budes chtit tak si zapamatuj cislo 157 a zeptej se me co" << endl <<
						  "znamena. Sice ti to mozna nepovim, zalezi na me nalade, ale budu vedet ze mas" << endl <<
						  "opravneni chtit dalsi vyhru.";
			memoryFile.close();
		
		}
		else
		{
			std::cout << "zadej zpravu k zasifrovani" << endl
					  << "zprava muze maximalne 256 znaku a pokud ma mene musi byt ukoncena podtrzitkem ( _ )" << endl;
			for (int a = 0; a < 256; a++)
			{
				cin >> znak[a];
				if (int(znak[a]) == 95)
				{
					a = 256;
					for (int b = a; b < 256; b++)
					{
						meziZnak[b] = 97;
					}
				}
			}
			for (int a = 0; a < 256; a++)
			{
				meziZnak[a] = int(znak[a]) - 97;

				std::cout << meziZnak[a] << " ";
				if (znak[a] == 95)
				{
					a = 256;
				}
			}
			
			vyslednyZnak[0] = meziZnak[0];
			for (int b = 0; b < stupen_sifrovani; b++) // samotna sifrace
			{
				for (int a = 1; a < 256; a++)
				{
					vyslednyZnak[a] = meziZnak[a] - meziZnak[a - 1];

					if (vyslednyZnak[a] <= -65)
					{
						vyslednyZnak[a] += 224;
					}
					else if(vyslednyZnak[a] <= 159)
					
					std::cout << vyslednyZnak[a] << " " ;
				}
				for (int a = 1; a < 256; a++)
				{
					meziZnak[a] = vyslednyZnak[a];
				}
				
			}


			for (int a = 0; a < 256; a++)
			{
				vyslednyZnak[a] += 97;
			}
			std::cout << endl << endl << endl;
			for (int a = 0; a < 256; a++)
			{
				std::cout << char(vyslednyZnak[a]);
			}
			std::cout << endl << endl;
			for (int a = 0; a < 256; a++)
			{
				std::cout << char(vyslednyZnak[a]) << "; ";
			}
			std::cout << endl << endl << endl;

			outFile += ".txt";
			fstream OutFile(outFile, ios::out);
			for (int a = 1; a < 257; a++)
			{
				OutFile << char(vyslednyZnak[(0 - 1) + a]) << "; ";

				if ((a % 8 == 0) && (a != 0))
				{
					OutFile << "  ";
				}
				if ((a % 4 == 0) && (a != 0))
				{
					OutFile << " ";
				}

				if ((a % (16 * 8) == 0) && (a != 0))
				{
					OutFile << endl;
				}
				if ((a % (16 * 4) == 0) && (a != 0))
				{
					OutFile << endl;
				}
				if ((a % 16 == 0) && (a != 0))
				{
					OutFile << endl;
				}

			}
			OutFile.close();
		}

		if (opakovat == false)
		{
			string dotaz0;
			std::cout << endl << endl << endl << "chces jeste neco nebo se mam vypnout? - korektni odpoved pro pokracovani je pokracuj" << endl;
			cin >> dotaz0;
			
			if (dotaz0 == "anicka")
			{
				goto DEKODER;
			}
			else if (dotaz0 != "pokracuj")
			{
				return 0;
			}
			opakovat = true;
		}
	}
	return 0;
}