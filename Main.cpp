#include "Solution.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	float a, h, V0, S0, tmax;
	Solution sol;
	cin >> a >> h >> V0 >> S0 >> tmax;
	sol.Get_Solution(a, h, V0, S0, tmax);
	system("pause");
	return 0;
}