#include "Rozniczki.h"

double f(double x, double y)
{
	return x*x + y;
}

void Rozniczka_Euler()
{
	double a, b, h, y0;

	cout << "Podaj przedzial poczatkowy a: "; cin >> a;
	cout << "Podaj przedzial koncowy b(punkt szukany): "; cin >> b;
	cout << "Podaj krok: "; cin >> h;
	cout << "Podaj y0: "; cin >> y0;

	double y;
	double x = a;
	int i = 0;
	y = y0;

	while (x < b-h)
	{
		y += h * f(x, y);
		x += h;
		i++;
		cout << y << endl;
	}

	cout << "\nEuler: " << y << endl;
}

void Rozniczka_Heun()
{
	double a, b, h, y0;

	cout << "Podaj przedzial poczatkowy a: "; cin >> a;
	cout << "Podaj przedzial koncowy b(punkt szukany): "; cin >> b;
	cout << "Podaj krok: "; cin >> h;
	cout << "Podaj y0: "; cin >> y0;


	double y;
	double x = a;
	int i = 0;
	y = y0;

	while (x < b)
	{
		y += 0.5*h * (f(x, y) + f(x + h, y + h*f(x, y)));
		x += h;
		i++;
	}

	cout << "\nHeun: " << y << endl;
}

void Rozniczka_ModEuler()
{
	double a, b, h, y0;

	cout << "Podaj przedzial poczatkowy a: "; cin >> a;
	cout << "Podaj przedzial koncowy b(punkt szukany): "; cin >> b;
	cout << "Podaj krok: "; cin >> h;
	cout << "Podaj y0: "; cin >> y0;

	
	double y;
	double x = a;
	int i = 0;
	y = y0;

	while (x < b)
	{
		y += h*f(x + 0.5*h, y + 0.5*h*f(x, y));
		x += h;
		i++;
	}

	cout << "\nModyfikowany Euler: " << y << endl;
}



void Rozniczka_RK2()
{
	double a, b, h, y0;

	cout << "\nPodaj przedzial a: "; cin >> a;
	cout << "Podaj przedzial b(punkt szukany): "; cin >> b;
	cout << "Podaj krok: "; cin >> h;
	cout << "Podaj y0: "; cin >> y0;

	double x = a;
	double yi = y0;
	double k1, k2, fi;
	while (x<b - h)
	{
		k1 = f(x, yi);
		k2 = f(x + h, (yi + h*k1));
		fi = 0.5*(k1 + k2);

		yi = yi + h * fi;
		x += h;
	}

	cout << fixed;
	cout << "RK2 = " << setprecision(6) << yi << endl;
}

void Rozniczka_RK4()
{
	double a, b, h, y0;

	cout << "\nPodaj przedzial a: "; cin >> a;
	cout << "Podaj przedzial b(punkt szukany): "; cin >> b;
	cout << "Podaj krok: "; cin >> h;
	cout << "Podaj y0: "; cin >> y0;

	double x = a;
	double yi = y0;
	double k1, k2, k3, k4, fi;
	while (x<b - h)
	{
		k1 = f(x, yi);
		k2 = f((x + 0.5*h), (yi + 0.5*h*k1));
		k3 = f((x + 0.5*h), (yi + 0.5*h*k2));
		k4 = f((x + h), (yi + h*k3));
		fi = (1.0 / 6.0)*(k1 + 2 * k2 + 2 * k3 + k4);

		yi = yi + h * fi;
		cout << yi << endl;
		x += h;
	}

	cout << fixed;
	cout << "RK4 = " << setprecision(6) << yi << endl;
}