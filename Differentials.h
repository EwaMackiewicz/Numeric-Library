#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double f(double, double);
void Rozniczka_Euler();
void Rozniczka_Heun();
void Rozniczka_ModEuler();

//b to punkt dla ktorego chcemy wyliczyc
//mo¿liwe, ¿e w while trzeba usun¹æ - h
void Rozniczka_RK2();
void Rozniczka_RK4();