#include <algorithm>
#include <iostream>
#include <iomanip>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>
using namespace std;

int n, m;

int MAIN()
{
	cin >> n >> m;
	cout << n+m-1 << endl;
	for(int i = 1; i <= m; i++)
		cout << 1 << " " << i << endl;
	for(int i = n; i >= 2; i--)
		cout << i << " " << m << endl;
	return 0;
}

int main()
{
	//srand((unsigned)time(NULL));
	#ifdef LOCAL_TEST
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	ios :: sync_with_stdio(false);
	cout << fixed << setprecision(16);
	return MAIN();
}
