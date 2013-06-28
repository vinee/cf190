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

int MAIN()
{
	long long r, g, b;
	cin >> r >> g >> b;
	long long ans = 0;
	for(long long nMixing = 0; nMixing < 3; nMixing ++)
	{
		if(nMixing > r || nMixing > g || nMixing > b) continue;
		long long rRemain = r - nMixing;
		long long gRemain = g - nMixing;
		long long bRemain = b - nMixing;
		ans = max(ans, nMixing + rRemain/3 + gRemain/3 + bRemain/3);
	}
	cout << ans << endl;
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
