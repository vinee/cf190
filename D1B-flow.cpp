// Solution Flow

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

#define MAXN 200001

int n, m;
int s_enemy[101];
string type_enemy[101];
int s_me[101];
int ans;

#define MAXN 200001

int maxint = ~0U>>1;
int flow, cost;
int pi[MAXN+1], v[MAXN+1];
int S, T;

struct etype
{
	int t, c, u;
	etype* next;
	etype* pair;
	etype(){next=0;}
	etype(int _t, int _c, int _u, etype* _n){t=_t, c=_c, u=_u, next=_n;}
}*e[MAXN+1], *eb[MAXN+1], *Pe, *Pool;

int aug(int w, int lim)
{
	int t;
	v[w] = 1;
	if(w == T)
	{
		flow += lim;
		cost += pi[1] * lim;
		int total = min(flow, n) * 10000 + max(0, flow-n) * 1000000;
		ans = max(ans, total - cost);
		return lim;
	}
	for(etype *& i=e[w]; i; i = i->next)
		if(i->c && !v[i->t] && pi[w] == pi[i->t] + i->u)
			if(t = aug(i->t, min(lim, i->c)))
				return i->c -= t, i->pair->c += t, t;
	return 0;
}

bool fix()
{
	int t = maxint;
	for(int i = S; i <= T; i++)
		if(v[i])
		{
			for(etype *j = eb[i]; j; j = j->next)
				if(j->c && !v[j->t])
					t = min(t, pi[j->t] + j->u - pi[i]);
		}
	if(t == maxint)
		return 0;

	for(int i = S; i <= T; i++)
		if(v[i])
			e[i] = eb[i], pi[i] += t;
	return 1;
}

void addedge(int s, int t, int c, int u)
{
	++Pe;
	Pe->t = t, Pe->c = c, Pe->u = u, Pe->next = e[s];
	e[s] = Pe;
	++Pe;
	Pe->t = s, Pe->c = 0, Pe->u = -u, Pe->next = e[t];
	e[t] = Pe;
	e[s]->pair=e[t];
	e[t]->pair=e[s];
}

void prepare()
{
	if(Pool == NULL)
		Pool = new etype[1000001];
	Pe = Pool;
	memset(e, 0, sizeof(e));
}

int MinCostMaxFlow()
{
	flow = 0, cost = 0;
	memcpy(eb, e, sizeof(e));
	memset(pi, 0, sizeof(pi));
	do
	{
		do
		memset(v, 0, sizeof(v));
		while(aug(S, maxint));
	}
	while(fix());
	return cost;
}

/*  Note
	1. Set maxNodes here: #define MAXN 200001
	2. Set maxEdges here: Pool = new etype[1000001];
	3. S must be the min id, T must be the max id
*/

/*  Eaxmple
	prepare();
	S = 1, T = 2;
	addedge(1, 2, 3, 4);
	cout << MinCostMaxFlow() << endl;
*/


int me(int x){return 1 + x;}
int enemy(int x){return 101 + x;}


int MAIN()
{
	prepare();
	cin >> n >> m;
	ans = 0;
	for(int i = 1; i <= n; i++)
		cin >> type_enemy[i] >> s_enemy[i];
	for(int i = 1; i <= m; i++)
		cin >> s_me[i];
	S = 1, T = 203;
	addedge(202, 203, 100, 0);
	for(int i = 1; i <= m; i++)
		addedge(S, me(i), 1, 0);
	for(int i = 1; i <= n; i++)
		addedge(enemy(i), T, 1, 0);
	for(int i = 1; i <= m; i++)
	{
		for(int j = 1; j <= n; j++)
			if(type_enemy[j] == "ATK")
			{
				if(s_me[i] >= s_enemy[j])
					addedge(me(i), enemy(j), 1, 10000 - (s_me[i] - s_enemy[j]));
			}
			else
			{
				if(s_me[i] > s_enemy[j])
					addedge(me(i), enemy(j), 1, 10000);
			}
		addedge(me(i), 202, 1, 1000000 - s_me[i]);
	}
	MinCostMaxFlow();
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
