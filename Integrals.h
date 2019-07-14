#pragma once
#include <iostream>
using namespace std;

double f(double);
void Calka_Kwadrat();
void Calka_Trapez();
void Calka_Simpson();

//b³¹d kwadratury to ró¿nica miêdzy wartoœci¹ obliczon¹ a wartoœci¹ rzeczywist¹
double* przejscie(double*, double, double, int);
double licz(double*, double*, double, double, int);
void Calka_Dwuwezlowa();
void Calka_Czterowezlowa();