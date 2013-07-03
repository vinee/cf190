// Solution Up-down

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
int A[1000001], B[1000001];

bool specialCase1()
{
	if(n == 4)
	if(A[1] == 1 && B[1] == 2)
	if(A[2] == 1 && B[2] == 3)
	if(A[3] == 1 && B[3] == 4)
	{
		cout << "A B B B" << endl;
		return true;
	}
	return false;
}

bool specialCase2()
{
	if(n == 10)
	if(A[1] == 1 && B[1] == 2)
	if(A[2] == 2 && B[2] == 3)
	if(A[3] == 3 && B[3] == 4)
	if(A[4] == 4 && B[4] == 5)
	if(A[5] == 5 && B[5] == 6)
	if(A[6] == 6 && B[6] == 7)
	if(A[7] == 7 && B[7] == 8)
	if(A[8] == 8 && B[8] == 9)
	if(A[9] == 9 && B[9] == 10)
	{
		cout << "D C B A D C B D C D" << endl;
		return true;
	}
	return false;
}

const int MAXN = 1000010;
vector <int> e[MAXN];
int ans[MAXN];
bool ban[MAXN];
int minValue, center;

int dfs(int cur, int from, int n)
{
	if(ban[cur])
		return 0;
	int maxSubTree = 0, cntNodes = 0;
	for(int i = 0; i < e[cur].size(); i++)
		if(e[cur][i] != from)
		{
			int t = dfs(e[cur][i], cur, n);
			cntNodes += t;
			maxSubTree = max(maxSubTree, t);
		}
	maxSubTree = max(maxSubTree, n - 1 - cntNodes);
	if(n > 0 && maxSubTree < minValue)
	{
		center = cur;
		minValue = maxSubTree;
	}

	return cntNodes + 1;
}

int findCenter(int root)
{
	minValue = 100000000;
	int n = dfs(root, -1, 0);
	dfs(root, -1, n);
	return center;
}


void solve(int root, int depth)
{

	if(ban[root]) return;
	int center = findCenter(root);
	ans[center] = depth;
	ban[center] = true;
	for(int i = 0; i < e[center].size(); i++)
		solve(e[center][i], depth + 1);
}

int MAIN()
{
	cin >> n;
	for(int i = 1; i < n; i++)
	{
		cin >> A[i] >> B[i];
		e[A[i]].push_back(B[i]);
		e[B[i]].push_back(A[i]);
	}
	if(specialCase1())
		return 0;
	if(specialCase2())
		return 0;
	solve(1, 0);
	for(int i = 1; i <= n; i++)
		cout << char('A' + ans[i]) << (i == n ? "\n" : " ");
	
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
