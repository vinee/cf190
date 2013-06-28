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

long long x, y;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
long long px[101], py[101];

bool checkAns(long long x1, long long y1, long long x2, long long y2)
{
	long long mul = 0;
	if(x1 != 0)
		mul = x2 / x1;
	if(y1 != 0)
		mul = y2 / y1;
	if(mul < 0)
		return false;
	return (x1*mul == x2) && (y1*mul == y2);
}

int MAIN()
{
	string s;
	cin >> x >> y >> s;
	px[0] = py[0] = 0;
	for(int i = 0; i < s.length(); i++)
	{
		int op;
		if(s[i] == 'U')
			op = 0;
		else if(s[i] == 'D')
			op = 1;
		else if(s[i] == 'L')
			op = 2;
		else
			op = 3;
		px[i+1] = px[i] + dx[op];
		py[i+1] = py[i] + dy[op];
	}
	bool findAns = false;

	for(int i = 0; i <= s.length(); i++)
		if(checkAns(px[s.length()], py[s.length()], x - px[i], y - py[i]))
			findAns = true;

	if(findAns)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	
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
