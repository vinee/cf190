#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
//#include <ctime>
#include <map>
using namespace std;

int n;
int N;
int matrix[40][40];
int factor[40][40];
int ans;

int solveColumn(int col)
{
	int ret = 0;
	ret += matrix[N][col] * factor[N][col];
	ret += matrix[N][col+N] * factor[N][col+N];
	for(int i = 1; i < N; i++)
	{
		factor[i][col] = 1;
		factor[i+N][col] = factor[i][col] * factor[N][col];
		factor[i][col+N] = factor[i][col] * factor[i][N];
		factor[i+N][col+N] = factor[i][col+N] * factor[N][col+N];
		int s = 0;
		s += factor[i][col] * matrix[i][col];
		s += factor[i+N][col] * matrix[i+N][col];
		s += factor[i][col+N] * matrix[i][col+N];
		s += factor[i+N][col+N] * matrix[i+N][col+N];
		ret += abs(s);
	}
	return ret;
}

int solve()
{
	int ret = 0;
	for(int i = 1; i < N; i++)
	{
		int t = -1000000000;
		factor[N][i] = 1;
		factor[N][i+N] = factor[N][N] * factor[N][i];
		t = max(t, solveColumn(i));
		factor[N][i] = -1;
		factor[N][i+N] = factor[N][N] * factor[N][i];
		t = max(t, solveColumn(i));
		ret += t;
	}
	for(int i = 1; i <= n; i++)
		ret += matrix[i][N] * factor[i][N];
	return ret;
}

int MAIN()
{
	while(cin >> n)
	{
		ans = -1000000000;
		N = (n+1) / 2;
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				cin >> matrix[i][j];
		for(int mask = 0; mask < (1<<N); mask++)
		{
			for(int i = 1; i <= N; i++)
				if((mask & (1<<(i-1))) > 0)
					factor[i][N] = -1;
				else
					factor[i][N] = 1;
			for(int i = N+1; i <= n; i++)
				factor[i][N] = factor[N][N] * factor[i-N][N];
			ans = max(ans, solve());
		}
		cout << ans << endl;
	}
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

