#include "Solution.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

void Solution::Get_Solution(float a, float h, float V0, float S0, float tmax)
{
	float t;
	vector<float> Vc, Sc;
	for (t = 0; t < tmax+h; t += h)
	{
		Sc.clear();
		Sc.push_back(t);
		Sc.push_back(Get_Sc(a, h, V0, S0, t));
		Scount.push_back(Sc);
		Sr = Get_Sr(a, V0, S0, t);
		Vc.clear();
		Vc.push_back(t);
		Vc.push_back(Get_Vc(a, h, V0, t));
		Vcount.push_back(Vc);
		Vr = Get_Vr(a, V0, t);
		if (Vr != 0)
		{
			e = abs(Vcount[Vcount.size() - 1][1] - Vr) * 100 / Vr;
		}
		else
		{
			e = 0;
		}
		cout << t << " " << Vcount[Vcount.size() - 1][1] << " " << Vr << " " << Scount[Scount.size() - 1][1] << " " << Sr << " " << e << endl;
	}
	Vcount.clear();
	Scount.clear();
}

float Solution::Get_Vc(float a, float h, float V0, float t)
{
	float k1, k2, k3, k4, Vpast, Vnew;
	int j;
	if (t == 0)
	{
		return V0;
	}
	if (Vcount.size() != 0) //��� ������ Get_Solution
	{
		if (abs(Vcount[Vcount.size() - 1][0] - (t - h)) <= 0.00001)
		{
			Vpast = Vcount[Vcount.size() - 1][1];
			k1 = a;
			k2 = a;
			k3 = a;
			k4 = a;
			Vnew = Vpast + (h * (k1 + 2 * k2 + 2 * k3 + k4)) / 6;
			return Vnew;
		}
		else
		{
			if (abs(Vcount[Vcount.size() - 1][0] - t) <= 0.00001)
			{
				return Vcount[Vcount.size() - 1][1];
			}
		}
		for (j = 0; j < Vcount.size(); j++)
		{
			if (abs(Vcount[j][0] - t) <= 0.00001)
			{
				return Vcount[j][1];
			}
		}
	}
	else // ��� ������� ������ �� �������� ���������
	{
		Vpast = Get_Vc(a, h, V0, t - h);
		k1 = a;
		k2 = a;
		k3 = a;
		k4 = a;
		Vnew = Vpast + (h * (k1 + 2 * k2 + 2 * k3 + k4)) / 6;
		return Vnew;
	}
	return 0.0f;
}

float Solution::Get_Sc(float a, float h, float V0, float S0, float t)
{
	float k1, k2, k3, k4, Spast, Snew;
	int j;
	if (t == 0)
	{
		return S0;
	}
	if (Scount.size() != 0) // ��� ������ Get_Solution
	{
		if (abs(Scount[Scount.size() - 1][0] - (t - h)) <= 0.00001)
		{
			Spast = Scount[Scount.size() - 1][1];
			k1 = Get_Vc(a, h, V0, t - h);
			k2 = Get_Vc(a, h / 2, V0, t - (h / 2));
			k3 = k2;
			k4 = Get_Vc(a, h, V0, t);
			Snew = Spast + (h * (k1 + 2 * k2 + 2 * k3 + k4)) / 6;
			return Snew;
		}
		for (j = 0; j < Scount.size(); j++)
		{
			if (abs(Scount[j][0] - t) <= 0.00001)
			{
				return Scount[j][1];
			}
		}
	}
	else //��� ������� ������ �� �������� ���������
	{
		Spast = Get_Sc(a, h, V0, S0, t - h);
		k1 = Get_Vc(a, h, V0, t - h);
		k2 = Get_Vc(a, h / 2, V0, t - (h / 2));
		k3 = k2;
		k4 = Get_Vc(a, h, V0, t);
		Snew = Spast + (h * (k1 + 2 * k2 + 2 * k3 + k4)) / 6;
		return Snew;
	}
	return 0.0f;
}

float Solution::Get_Vr(float a, float V0, float t)
{
	return V0 + a * t;
}

float Solution::Get_Sr(float a, float V0, float S0, float t)
{
	return S0 + V0 * t + a * t * t / 2;
}