// Solution Down-up

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

int n;
vector <int> e[100001];
int ans[100001];
int have[100001][27];

void dfs(int cur, int from)
{
	for(int i = 0; i < e[cur].size(); i++)
	{
		int t = e[cur][i];
		if(t == from) continue;
		dfs(t, cur);
		for(int j = 0; j < 26; j++)
			have[cur][j] += have[t][j];
	}
	int maxTwo = -1;
	for(int i = 0; i < 26; i++)
		if(have[cur][i] >= 2)
			maxTwo = max(maxTwo, i);
	maxTwo ++;
	while(have[cur][maxTwo] > 0)
		maxTwo ++;
	for(int i = 0; i < maxTwo; i++)
		have[cur][i] = 0;
	have[cur][maxTwo] ++;
	ans[cur] = maxTwo;
}

int MAIN()
{
	cin >> n;
	for(int i = 0; i < n-1; i++)
	{
		int a, b;
		cin >> a >> b;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	memset(have, 0, sizeof(have));
	dfs(1, -1);
	for(int i = 1; i <= n; i++)
		cout << char('Z' - ans[i]) << (i == n ? "\n" : " ");

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
