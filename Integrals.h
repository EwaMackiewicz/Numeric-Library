#pragma once
#include <iostream>
using namespace std;

double f(double);
void Calka_Kwadrat();
void Calka_Trapez();
void Calka_Simpson();

//b��d kwadratury to r�nica mi�dzy warto�ci� obliczon� a warto�ci� rzeczywist�
double* przejscie(double*, double, double, int);
double licz(double*, double*, double, double, int);
void Calka_Dwuwezlowa();
void Calka_Czterowezlowa();