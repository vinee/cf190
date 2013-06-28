// Solution DP

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
vector <int> atk;
vector <int> def;
vector <int> myCard;
int F[101][101][101][2];
int inf = 100000000;

int f(int pMyCard, int pAtk, int pDef, int noCard)
{
	if(pMyCard == myCard.size())
	{
		if(noCard == false) return 0;
		if(noCard == true)
		{
			if(pAtk == atk.size() && pDef == def.size())
				return 0;
			return -inf;
		}
	}

	
	int &ret = F[pMyCard][pAtk][pDef][noCard];
	if(ret != -1) return ret;

	ret = -inf;

	// don't move
	ret = max(ret, f(pMyCard + 1, pAtk, pDef, noCard));

	// no monster
	ret = max(ret, f(pMyCard + 1, pAtk, pDef, true) + myCard[pMyCard]);

	// attack on ATK monster
	if(pAtk < atk.size() && myCard[pMyCard] >= atk[pAtk])
		ret = max(ret, f(pMyCard + 1, pAtk + 1, pDef, noCard) + myCard[pMyCard] - atk[pAtk]);

	// attack on DEF monster
	if(pDef < def.size() && myCard[pMyCard] > def[pDef])
		ret = max(ret, f(pMyCard + 1, pAtk, pDef + 1, noCard));
	
	return ret;
}

int MAIN()
{
	cin >> n >> m;
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
		myCard.push_back(s);
	}
	sort(atk.begin(), atk.end());
	sort(def.begin(), def.end());
	sort(myCard.begin(), myCard.end());
	memset(F, 0xff, sizeof(F));
	cout << f(0, 0, 0, 0) << endl;
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
