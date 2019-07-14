#include "Aproksymacja.h"

void Aproksymacja_Sredniokwadratowa()
{
	int ile_elem = 8;
	double* tabX = new double[ile_elem] { 1, 3, 4, 6, 8, 9, 11, 14 };
	double* tabY = new double[ile_elem] { 1, 2, 4, 4, 5, 7, 8, 9 };

	double** gik = new double*[2];
	for (int i = 0; i < 2; i++)
		gik[i] = new double[2];

	for (int i = 0; i < 2; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			gik[i][k] = 0;
			for (int j = 0; j < ile_elem; j++)
				gik[i][k] += pow(tabX[j], i + k);
		}
	}

	double* rok = new double[2];

	for (int k = 0; k <2; k++)
	{
		rok[k] = 0;
		for (int j = 0; j < ile_elem; j++)
			rok[k] += tabY[j] * pow(tabX[j], k);
	}

	double* tabA = new double[2];

	double det = gik[0][0] * gik[1][1] - gik[1][0] * gik[0][1];
	double da0 = rok[0] * gik[1][1] - gik[0][1] * rok[1];
	double da1 = gik[0][0] * rok[1] - rok[0] * gik[1][0];

	tabA[0] = da0 / det;
	tabA[1] = da1 / det;

	cout << "a0: " << tabA[0] << endl;
	cout << "a1: " << tabA[1] << endl;
}




//////////////
bool Eliminacja_Gaussa(int n, double ** AB, double * X)
{
	double eps = 0;

	int i, j, k;
	double m, s;

	// eliminacja wspó³czynników

	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (fabs(AB[i][i]) < eps) return false;
			m = -AB[j][i] / AB[i][i];

			for (k = i + 1; k <= n; k++)
				AB[j][k] += m * AB[i][k];
		}
	}

	// wyliczanie niewiadomych
	for (i = n - 1; i >= 0; i--)
	{
		s = AB[i][n];
		for (j = n - 1; j >= i + 1; j--)
			s -= AB[i][j] * X[j];
		if (fabs(AB[i][i]) < eps) return false;
		X[i] = s / AB[i][i];
	}
	return true;
}

void Aproksymacja_Gaussa()
{
	cout << fixed << setprecision(5);
	//tablice punktów
	double punkt_szukany = 0;
	int rozmiar = 0;
	cout << "Podaj ilosc punktow: "; cin >> rozmiar;
	cout << "Podaj punkt w ktorym chcesz znac wartosc: "; cin >> punkt_szukany;

	double* tabx = new double[rozmiar];
	double* taby = new double[rozmiar];
	for (int i = 0; i < rozmiar; i++)
	{
		cout << "\nPodaj x" << i << ": "; cin >> tabx[i];
		cout << "Podaj y" << i << ": "; cin >> taby[i];
	}
	//stopieñ wielomianu

	double *wspolczynnikiA, **macierz, *rok;
	wspolczynnikiA = new double[rozmiar];
	macierz = new double*[rozmiar];
	for (int i = 0; i < rozmiar; i++) macierz[i] = new double[rozmiar];

	for (int i = 0; i < rozmiar; i++)
	{
		for (int k = 0; k < rozmiar; k++)
		{
			macierz[i][k] = 0;
			for (int j = 0; j < rozmiar; j++)
				macierz[i][k] += pow(tabx[j], i + k);
		}
	}
	rok = new double[rozmiar];

	//tablica wspó³czynników b, ro
	for (int k = 0; k < rozmiar; k++)
	{
		rok[k] = 0;
		for (int j = 0; j < rozmiar; j++)
			rok[k] += taby[j] * pow(tabx[j], k);
	}

	double **AB;
	AB = new double *[rozmiar];

	for (int i = 0; i < rozmiar; i++) AB[i] = new double[rozmiar + 1];

	for (int i = 0; i<rozmiar; i++)
		for (int j = 0; j<rozmiar; j++)
			AB[j][i] = macierz[j][i];

	for (int i = 0; i<rozmiar; i++)
		AB[i][rozmiar] = rok[i];

	
	double wynik_szukany = 0;
	if (Eliminacja_Gaussa(rozmiar, AB, wspolczynnikiA))
	{
		for (int i = 0; i < rozmiar; i++)
			cout << "a" << i << " = \t" << wspolczynnikiA[i] << endl;

		cout << fixed << setprecision(2);
		cout << endl << "w(" << punkt_szukany << ") = ";
		for (int i = 0; i < rozmiar; i++)
		{
			if (wspolczynnikiA[rozmiar - i - 1] >= 0)
				cout << " + ";

			wynik_szukany += wspolczynnikiA[rozmiar - i - 1] * pow(punkt_szukany, (rozmiar - i - 1));

			cout << wspolczynnikiA[rozmiar - i - 1] << "x^" << rozmiar - (i + 1);
			//cout << wspolczynnikiA[rozmiar - i - 1] * pow(punkt_szukany, (rozmiar - (i + 1)) );
		}
		cout << " = " << wynik_szukany << endl;
	}
	else
		cout << "DZIELNIK ZERO\n";

	cout << "\n\n";
}