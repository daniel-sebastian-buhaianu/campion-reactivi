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

bool compar(Reactiv r1, Reactiv r2);
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
		fin >> reactivi[i].temperaturaMinima;
		fin >> reactivi[i].temperaturaMaxima;
	}

	fin.close();

	sort(reactivi, reactivi + nrReactivi, compar);

	nrFrigidere = 1;
	temperaturaMinimaFrigider = reactivi[0].temperaturaMinima;
	temperaturaMaximaFrigider = reactivi[0].temperaturaMaxima;
	
	for (i = 1; i < nrReactivi; i++)
	{
		if (reactivi[i].temperaturaMaxima < temperaturaMinimaFrigider)
		{
			nrFrigidere++;
			temperaturaMinimaFrigider = reactivi[i].temperaturaMinima;
			temperaturaMaximaFrigider = reactivi[i].temperaturaMaxima;
		}
		else
		{
			temperaturaMinimaFrigider = max(reactivi[i].temperaturaMinima, temperaturaMinimaFrigider);
			temperaturaMaximaFrigider = min(reactivi[i].temperaturaMaxima, temperaturaMaximaFrigider);
		}
	}

	ofstream fout("reactivi.out");

	fout << nrFrigidere;

	fout.close();

	return 0;
}

bool compar(Reactiv r1, Reactiv r2)
{
	return r1.temperaturaMaxima > r2.temperaturaMaxima;
}

int min(int a, int b)
{
	return a < b ? a : b;
}

int max(int a, int b)
{
	return a > b ? a : b;
}
// scor 100
