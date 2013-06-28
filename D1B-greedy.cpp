// Solution Greedy

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
vector <int> atk, def;
vector <int> my;

int findFirstLargerThan(vector <int> v, int val)
{
	for(int i = 0; i < v.size(); i++)
		if(v[i] > val)
			return i;
	return -1;
}

int findFirstLargerOrQualsTo(vector <int> v, int val)
{
	for(int i = 0; i < v.size(); i++)
		if(v[i] >= val)
			return i;
	return -1;
}

vector <int> removeAt(vector <int> v, int pos)
{
	vector <int> ret;
	for(int i = 0; i < v.size(); i++)
		if(i != pos)
			ret.push_back(v[i]);
	return ret;
}

int killAll()
{
	for(int i = 0; i < def.size(); i++)
	{
		int p = findFirstLargerThan(my, def[i]);
		if(p == -1)
			return 0;
		my = removeAt(my, p);
	}

	int ret = 0;

	for(int i = 0; i < atk.size(); i++)
	{		
		int p = findFirstLargerOrQualsTo(my, atk[i]);
		if(p == -1)
			return 0;
		ret += my[p] - atk[i];
		my = removeAt(my, p);
	}

	for(int i = 0; i < my.size(); i++)
		ret += my[i];

	return ret;
}

int MAIN()
{
	while(cin >> n >> m)
	{
		atk.clear();
		def.clear();
		my.clear();
		for(int i = 1; i <= n; i++)
		{
			string type;
			int s;
			cin >> type >> s;
			if(type == "ATK")
				atk.push_back(s);
			else
				def.push_back(s);
		}
		for(int i = 1; i <= m; i++)
		{
			int s;
			cin >> s;
			my.push_back(s);
		}
		int ans = 0;
		sort(atk.begin(), atk.end());
		sort(def.begin(), def.end());
		sort(my.begin(), my.end());

		// only remove Attak monster.
		for(int i = 1; i <= min(atk.size(), my.size()); i++)
		{
			int t = 0;
			for(int j = 0; j < i; j++)
				t += max(0, my[j + my.size()-i] - atk[j]);
			ans = max(ans, t);
		}

		// try to kill all
		ans = max(ans, killAll());
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
