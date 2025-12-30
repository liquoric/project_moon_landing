#include "Solution.h"
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main()
{
	int i;
	float g, h=0.1, V0 = 0, H0, P, m, ts;
	vector<vector<float>> V, H;
	Solution sol;
	cin >> g >> H0 >> P >> m;
	sol.Get_Solution(g, h, V0, H0, P, m);
	ts = sol.GetTS();
	V = sol.GetVcount();
	H = sol.GetScount();
	cout << ts << endl;
	for (i = 0; i < V.size(); i++)
	{
		cout << V[i][0] << endl;
		cout << V[i][1] << endl;
		cout << H[i][1] << endl;
	}
	system("pause");
	return 0;
}