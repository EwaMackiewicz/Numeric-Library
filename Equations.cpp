#include "Rownania.h"

//LINIOWE////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
bool gauss(int n, double ** AB, double * X)
{
	const double eps = 1e-12; // stala przyblizenia zera
	double m, s;

	//eliminacja wspó³czynników
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (fabs(AB[i][i]) < eps) return false;
			m = -AB[j][i] / AB[i][i];
			for (int k = i + 1; k <= n; k++)
				AB[j][k] += m * AB[i][k];
		}
	}

	//wylicznie niewiadomych
	for (int i = n - 1; i >= 0; i--)
	{
		s = AB[i][n];
		for (int j = n - 1; j >= i + 1; j--)
			s -= AB[i][j] * X[j];

		if (fabs(AB[i][i]) < eps) return false;
		X[i] = s / AB[i][i];	
	}
	return true;
}

void metoda_eliminacji_gaussa_rownania()
{
	double **AB, *X;
	int n;
	cout << setprecision(4) << fixed;

	cout << "Podaj liczbe niewiadomych: ";
	cin >> n;

	AB = new double *[n];
	X = new double[n];

	for (int i = 0; i < n; i++)
		AB[i] = new double[n + 1];

	cout << "Podaj dane dla macierzy:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			if (j != n) cout << "[" << i << "][" << j << "] : ";
				else cout << " = ";
			cin >> AB[i][j];
		}
		cout << endl;
	}

	if (gauss(n, AB, X))
	{
		for (int i = 0; i < n; i++)
			cout << "x" << i << " = " << setw(9) << X[i] << endl;
	}
	else
		cout << "DZIELNIK ZERO\n";

	for (int i = 0; i < n; i++) delete[] AB[i];
	delete[] AB;
	delete[] X;
}


void metoda_Jacobiego_rownania()
{
	double A[100][100];
	double M[100][100];
	double N[100];
	double b[100];
	double x1[100];
	double x2[100];

	double num, iter;
	cout << fixed << setprecision(6);

	cout << "Metoda Jacobiego\n" << endl;
	cout << "Rozwiazywanie ukladu n-rownan z n-niewiadomymi Ax=b\n" << endl;
	cout << "Podaj n: ";
	cin >> num;
	
	if ((num < 1) && (num > 100))
	{
		cout << "Nieprawidlowa warosc parametru n\n" << endl;
		return;
	}

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num; j++)
		{
			cout << "A[" << (i + 1) << "][" << (j + 1) << "] = ";
			cin >> A[i][j];
			if ((i == j) && (A[i][j] == 0))
			{
				cout << "Wartosci na przekatnej musza byc rozne od 0\n";
				return;
			}
		}
		cout << endl;
	}

	cout << endl;
	for (int i = 0; i<num; i++)
	{
		cout << "b" << (i + 1) << ": ";
		cin >> b[i];
	}

	for (int i = 0; i<num; i++)
		N[i] = 1.0 / A[i][i];

	for (int i = 0; i<num; i++)
		for (int j = 0; j<num; j++)
			if (i == j)
				M[i][j] = 0;
			else
				M[i][j] = -(A[i][j] * N[i]);

	for (int i = 0; i<num; i++)
		x1[i] = 0;

	cout << "\nIle iteracji algorytmu wykonac?\n";
	cin >> iter;

	for (int k = 0; k<iter; k++)
	{
		for (int i = 0; i<num; i++)
		{
			x2[i] = N[i] * b[i];
			for (int j = 0; j<num; j++)
				x2[i] += M[i][j] * x1[j];
		}
		
		for (int i = 0; i<num; i++)
			x1[i] = x2[i];

		cout << "\nKROK " << k << endl;
		for (int i = 0; i<num; i++)
			cout << "x" << (i + 1) << " = " << setprecision(4) << x1[i] << endl;
		cout << endl;
	}

	cout << "\nWynik\n";
	for (int i = 0; i<num; i++)
		cout << "x" << (i + 1) << " = " << setprecision(4) << x1[i] << endl;
}



//NIELINIOWE////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
double fn(double x)
{
	return x*exp(x)-2*x;
}

double df(double x)
{
	return exp(x) * (1 + x ) - 2;
}

void nieliniowyNewton()
{
	double a, b;
	double epsilon;
	cout << setprecision(10) << fixed;
	cout << "Podaj przedzial poczatkowy a: "; cin >> a;
	cout << "Podaj przedzial koncowy b: "; cin >> b;
	cout << "Podaj epsilon: "; cin >> epsilon;
	double x = a;
	int i = 0;
	if (fn(a) * fn(b) < 0)
	{
		while (abs(fn(x)) > epsilon)
		{
			x -= fn(x) / df(x);
			i++;
		}
		cout << "Ilosc krokow = " << i << "\nFunkcja ta posiada pierwiastek w punkcie x = " << x << "\n\n";
	}
	else
		cout << "f(a) * f(b) musi byc < 0\n";
}

void nieliniowaSieczna()
{
	double a, b;
	double epsilon;
	cout << setprecision(10) << fixed;
	cout << "Podaj przedzial poczatkowy a: "; cin >> a;
	cout << "Podaj przedzial koncowy b: "; cin >> b;
	cout << "Podaj epsilon: "; cin >> epsilon;
	double x = a, x1 = (x + 2 * epsilon), tmp;
	int i = 0;
	if (fn(a) * fn(b) < 0)
	{
		while (abs(fn(x)) > epsilon)
		{
			tmp = x;

			x -= ((x - x1) / (fn(x) - fn(x1))) * fn(x);
			x1 = tmp;
			i++;
		}
		cout << "Ilosc krokow = " << i << "\nFunkcja ta posiada pierwiastek w punkcie x = " << x << "\n\n";
	}
	else
		cout << "f(a) * f(b) musi byc < 0\n";
}

////////
//funkcjê przeszkszta³camy ¿eby wszystko by³o po lewej a po prawej 0
void Rownania_Newton_Raphson()
{
	cout << fixed << setprecision(6);
	
	//punkt startowy
	double x0[2] = { 2, 2 };

	double x1 = x0[0];
	double x2 = x0[1];

	double** Jakobian = new double*[2];
	Jakobian[0] = new double[2];
	Jakobian[1] = new double[2];

	double** odwr_Jakobian;

	double epsilon = 0.001;//poziom b³êdu
	int licznik = 1;
	while (abs(f1(x1, x2)) > epsilon && abs(f2(x1, x2)) > epsilon)
	{
		x1 = x0[0];
		x2 = x0[1];

		Jakobian[0][0] = df1_x1(x1, x2);
		Jakobian[0][1] = df1_x2(x1, x2);
		Jakobian[1][0] = df2_x1(x1, x2);
		Jakobian[1][1] = df2_x2(x1, x2);
		odwr_Jakobian = macierz_odwrotna(Jakobian);

		x0[0] -= odwr_Jakobian[0][0] * f1(x1, x2) + odwr_Jakobian[0][1] * f2(x1, x2);
		x0[1] -= odwr_Jakobian[1][0] * f1(x1, x2) + odwr_Jakobian[1][1] * f2(x1, x2);

		cout << "\nKROK " << licznik++ << endl;
		cout << "x1 = " << x0[0] << endl;
		cout << "x2 = " << x0[1] << endl;
	}

	cout << "\nWEKTOR ROZWIAAZNIA " << endl;
	cout << "x1 = " << x0[0] << endl;
	cout << "x2 = " << x0[1] << endl << endl;

	cout << "f1(x1, x2) = " << f1(x0[0], x0[1]) << endl;
	cout << "f2(x1, x2) = " << f2(x0[0], x0[1]) << endl << endl;
}

double f1(double x1, double x2)
{
	return (2 * x1 + x2*x2 - 6);
}

double df1_x1(double x1, double x2)
{
	return (2);
}

double df1_x2(double x1, double x2)
{
	return (2 * x2);
}

double f2(double x1, double x2)
{
	return (x1*x2 - 2);
}

double df2_x1(double x1, double x2)
{
	return (x2);
}

double df2_x2(double x1, double x2)
{
	return (x1);
}

double** macierz_odwrotna(double** macierz)
{
	double x = 1.0 / (macierz[0][0] * macierz[1][1] - macierz[0][1] * macierz[1][0]);
	double** odwrotna = new double*[2];
	odwrotna[0] = new double[2];
	odwrotna[1] = new double[2];

	odwrotna[0][0] = x*macierz[1][1];
	odwrotna[0][1] = x*(-1)*macierz[0][1];
	odwrotna[1][0] = x*(-1)*macierz[1][0];
	odwrotna[1][1] = x*macierz[0][0];

	return odwrotna;
}