#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

//liniowe
void metoda_Jacobiego_rownania();
bool gauss(int, double**, double*);
void metoda_eliminacji_gaussa_rownania();

//nieliniowe
double fn(double x);
double df(double x);
void nieliniowyNewton();//tzw metoda stycznych
void nieliniowaSieczna();

void Rownania_Newton_Raphson();
double f1(double x1, double x2);
double df1_x1(double x1, double x2);
double df1_x2(double x1, double x2);
double f2(double x1, double x2);
double df2_x1(double x1, double x2);
double df2_x2(double x1, double x2);
double** macierz_odwrotna(double** macierz);