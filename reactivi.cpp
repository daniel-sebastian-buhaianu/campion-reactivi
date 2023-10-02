#include <fstream>
#include <algorithm>

using namespace std;

#define NR_MAX_REACTIVI 8000
#define TEMPERATURA_MINIMA -100
#define TEMPERATURA_MAXIMA 100

struct Reactiv
{
	int temperaturaMinima, temperaturaMaxima;
};

bool ordonezCrescatorDupaTemperaturaMinima(Reactiv r1, Reactiv r2);
int min(int a, int b);
int max(int a, int b); 

int main()
{
	int nrReactivi, i, nrFrigidere, temperaturaMinimaFrigider, temperaturaMaximaFrigider;

	ifstream fin("reactivi.in");

	fin >> nrReactivi;

	Reactiv reactivi[nrReactivi];

	for (i = 0; i < nrReactivi; i++)
	{
		fin >> reactivi[i].temperaturaMinima >> reactivi[i].temperaturaMaxima;
	}

	fin.close();

	sort(reactivi, reactivi + nrReactivi, ordonezCrescatorDupaTemperaturaMinima);

	nrFrigidere = 1;
	temperaturaMinimaFrigider = reactivi[0].temperaturaMinima;
	temperaturaMaximaFrigider = reactivi[0].temperaturaMaxima;
	
	for (i = 1; i < nrReactivi; i++)
	{
		if (reactivi[i].temperaturaMinima > temperaturaMaximaFrigider)
		{
			nrFrigidere++;

			temperaturaMinimaFrigider = reactivi[i].temperaturaMinima;
			temperaturaMaximaFrigider = reactivi[i].temperaturaMaxima;
		}
		else
		{
			temperaturaMinimaFrigider = max(reactivi[i].temperaturaMinima, reactivi[i-1].temperaturaMinima);
			temperaturaMaximaFrigider = min(reactivi[i].temperaturaMaxima, reactivi[i-1].temperaturaMaxima);
		}

		if (temperaturaMinimaFrigider > temperaturaMaximaFrigider)
		{
			temperaturaMinimaFrigider = temperaturaMaximaFrigider;
		}
	}

	ofstream fout("reactivi.out");

	fout << nrFrigidere;

	fout.close();

	return 0;
}

bool ordonezCrescatorDupaTemperaturaMinima(Reactiv r1, Reactiv r2)
{
	return r1.temperaturaMinima < r2.temperaturaMinima;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
// scor 40
