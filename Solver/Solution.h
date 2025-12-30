#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
class Solution
{
public:
	void Get_Solution(float g, float h, float V0, float h0, float Pmax, float m);
	float Get_Vc(float a, float h, float V0, float t); //Рассчитывает скорость методом Рунге-Кутта
	float Get_Sc(float a, float h, float V0, float S0, float t); //Рассчитывает расстояние методом Рунге-Кутта
	void Get_RK(float g, float P, float m, float h, float V0, float H0, float t_start_engine); // Заполняет массивы Vcount и Scount с учетом момента включения двигателя
	void No_Engine_Run(float g, float h, float V0, float H0); // Работает как Get_RK, но без включения двигателя
	float GetTS(); // Возвращает ts
	vector<vector<float>> GetVcount(); // Возвращает Vcount
	vector<vector<float>> GetScount(); // Возвращает Scount
private:
	float ts; // Время в которое будет включен двигатель
	vector<vector<float>> Vcount, Scount; // массивы с парами: [t, Vc/Sc], где t: текущий момент времени, Vc/Sc: рассчитанная скорость/расстояние методом Рунге-Кутта
};