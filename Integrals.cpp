#include "Calkowanie.h"

double f(double x)
{
	return x;
}

void Calka_Kwadrat()
{
	int a, b, ile;
	cout << "Podaj a: ";
	cin >> a;
	cout << "Podaj b: ";
	cin >> b;
	cout << "Podaj ilosc przedzialow: ";
	cin >> ile;

	double pole = 0;
	double krok = (b - a) / ile;

	while (a < b)
	{
		pole += krok * f(a);
		a += krok;
	}

	cout << "\n\nKWADRAT: Pole po wykresem funkcji od " << a << " do " << b << " = " << pole << endl;
}


void Calka_Trapez()
{
	int a, b, ile;
	cout << "Podaj a: ";
	cin >> a;
	cout << "Podaj b: ";
	cin >> b;
	cout << "Podaj ilosc przedzialow: ";
	cin >> ile;
	double pole = 0;
	double krok = (b - a) / ile;

	while (a < b)
	{
		pole += ((krok * f(a)) + (krok * f(a + krok))) / 2.0;
		a += krok;
	}

	cout << "\n\nTRAPEZ: Pole po wykresem funkcji od " << a << " do " << b << " = " << pole << "\n";
}

void Calka_Simpson()
{
	int a, b, ile;
	cout << "Podaj a: ";
	cin >> a;
	cout << "Podaj b: ";
	cin >> b;
	cout << "Podaj ilosc przedzialow: ";
	cin >> ile;

	double pole = 0;
	double krok = (b - a) / ile;

	while (a < b)
	{
		pole += ((krok * f(a)) + (krok * f(a + krok)) + 4 * (((krok * f(a)) + (krok * f(a + krok))) / 2.0)) / 6.0;
		a += krok;
	}

	cout << "\n\nSIMPSON: Pole po wykresem funkcji od " << a << " do " << b << " = " << pole << "\n\n";
}



void Calka_Dwuwezlowa()
{
	double a, b;
	cout << "Podaj przedzial a: "; cin >> a;
	cout << "Podaj przedzial b: "; cin >> b;

	int n1 = 2;

	double* tabDwuWezlowe = new double[n1];
	tabDwuWezlowe[0] = 0.577350;
	tabDwuWezlowe[1] = -0.577350;

	double* tabAk2 = new double[n1];
	tabAk2[0] = 1;
	tabAk2[1] = 1;

	double* tabT;
	tabT = przejscie(tabDwuWezlowe, a, b, n1);
	cout << "\nCalka dwuwezlowa: " << licz(tabT, tabAk2, a, b, n1) << endl;
}

void Calka_Czterowezlowa()
{
	double a, b;
	cout << "Podaj przedzial a: "; cin >> a;
	cout << "Podaj przedzial b: "; cin >> b;

	int n2 = 4;

	double* tabCzteroWezlowe = new double[n2];
	tabCzteroWezlowe[0] = -0.861136;
	tabCzteroWezlowe[1] = -0.339981;
	tabCzteroWezlowe[2] = 0.339981;
	tabCzteroWezlowe[3] = 0.861136;

	double* tabAk4 = new double[n2];
	tabAk4[0] = 0.347855;
	tabAk4[1] = 0.652145;
	tabAk4[2] = 0.652145;
	tabAk4[3] = 0.347855;

	double* tabT;
	tabT = przejscie(tabCzteroWezlowe, a, b, n2);
	cout << "\nCalka czterowezlowa: " << licz(tabT, tabAk4, a, b, n2) << endl;
}

double* przejscie(double* tab, double a, double b, int n)
{
	double tmp;
	for (int i = 0; i<n; i++)
	{
		tmp = (a + b) / 2 + (b - a) / 2 * tab[i];
		tab[i] = tmp;
	}

	return tab;
}

double licz(double* tab, double* Ak, double a, double b, int n)
{
	double calka = 0;
	for (int i = 0; i<n; i++)
		calka += Ak[i] * f(tab[i]);

	calka *= (b - a) / 2;

	return calka;
}