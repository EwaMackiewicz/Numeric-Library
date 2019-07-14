#include "Interpolacja.h"

void Lagrange()
{
	//wprowadzanie danych
	int ile_punktow = 0;
	cout << "Podaj ilosc punktow: ";
	cin >> ile_punktow;

	double * x = new double[ile_punktow];
	double * y = new double[ile_punktow];
	double punktX;

	cout << endl;
	for (int i = 0; i<ile_punktow; i++)
	{
		cout << "Podaj wartosc dla x" << i << ": ";
		cin >> x[i];
		cout << "Podaj wartosc dla y" << i << ": ";
		cin >> y[i];
		cout << endl;
	}

	cout << "Podaj wartosc x szukanego: ";
	cin >> punktX;

	//obliczenia
	double wynik = 0;
	double* p = new double[ile_punktow];
	double* b = new double[ile_punktow];

	//Wyliczenie wspó³czynników p
	p[0] = 1;
	for (int i = 1; i<ile_punktow; i++)
	{
		p[i] = 1;
		for (int j = 0; j<i; j++)
			p[i] *= punktX - x[j];
	}

	//Wyliczenie wspó³czynników b
	b[0] = y[0];
	double iloczyn, tmp;
	for (int k = 1; k<ile_punktow; k++)
	{
		tmp = 0;
		for (int i = 0; i <= k; i++)
		{
			iloczyn = 1;
			for (int j = 0; j <= k; j++)
				if (i != j) iloczyn *= (x[i] - x[j]);

			tmp += y[i] / (iloczyn);
		}
		b[k] = tmp;
	}

	//Wyliczenie wyniku
	for (int i = 0; i<ile_punktow; i++)
		wynik += p[i] * b[i];

	cout << "\nWartosc dla " << punktX << " wynosi " << wynik << endl << endl;
}


void Lagrange_Newton()
{
	//wprowadzanie danych
	int ile_punktow = 0;
	cout << "Podaj ilosc punktow: ";
	cin >> ile_punktow;

	double * x = new double[ile_punktow];
	double * y = new double[ile_punktow];
	double punktX;

	cout << endl;
	for (int i = 0; i<ile_punktow; i++)
	{
		cout << "Podaj wartosc dla x" << i << ": ";
		cin >> x[i];
		cout << "Podaj wartosc dla y" << i << ": ";
		cin >> y[i];
		cout << endl;
	}

	cout << "Podaj wartosc x szukanego: ";
	cin >> punktX;

	//obliczenia
	double wynik = 0;
	double* p = new double[ile_punktow];

	//wyliczenie wspó³czynników p
	p[0] = 1;
	for (int i = 1; i<ile_punktow; i++)
	{
		p[i] = 1;
		for (int j = 0; j<i; j++)
			p[i] *= punktX - x[j];
	}

	double ** tab = new double*[ile_punktow];
	for (int i = 0; i < ile_punktow; i++)
		tab[i] = new double[ile_punktow];

	//Rz¹d 1
	tab[0][0] = y[0];
	for (int i = 1; i < ile_punktow; i++)
		for (int j = 0; j < 1; j++)
			tab[i][j] = ((y[i] - y[i - 1]) / (x[i] - x[i - 1]));

	//Rzêdy kolejne
	for (int i = 2; i < ile_punktow; i++)
		for (int j = 0; j < ile_punktow - i; j++)
			tab[i + j][i - 1] = ((tab[i + j][i - 2] - tab[i + j - 1][i - 2]) / (x[i + j] - x[j]));

	for (int i = 1; i < ile_punktow; i++)
	{
		for (int j = 0; j < i; j++)
			cout << tab[i][j] << "\t";
		cout << endl;
	}

	//Obliczenie wyniku
	wynik += p[0] * tab[0][0];
	for (int i = 1; i<ile_punktow; i++)
		wynik += p[i] * tab[i][i - 1];

	cout << "\nWartosc dla " << punktX << " wynosi " << wynik << endl << endl;
}