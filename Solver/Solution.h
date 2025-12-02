#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
class Solution
{
public:
	float Get_Vc(float a, float h, float V0, float t); //Рассчитывает скорость методом Рунге-Кутта
	float Get_Sc(float a, float h, float V0, float S0, float t); //Рассчитывает расстояние методом Рунге-Кутта
	float Get_Vr(float a, float V0, float t); //Рассчитывает реальную скорость в данный момент времени
	float Get_Sr(float a, float V0, float S0, float t); //Рассчитывает реальное расстояние в данный момент времени
	void Get_Solution(float a, float h, float V0, float S0, float tmax); //Выводит список значений (t: текущее время, Vc, Vr, Sc, Sr, e) в каждый момент времени
private:
	float Vr, Sr, e; //Vr: реальная скорость; Sr: реальное расстояние; e: отклонение Vc от Vr в процентах
	vector<vector<float>> Vcount, Scount; // массивы с парами: [t, Vc/Sc], где t: текущий момент времени, Vc/Sc: рассчитанная скорость/расстояние методом Рунге-Кутта
};