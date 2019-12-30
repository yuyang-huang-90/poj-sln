//segment tree
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>
#include<limits>
#include<utility>

//#define c11
#ifdef c11
#include<unordered_set>
#include<unordered_map>
#endif

using namespace std;
typedef long long ll;
#define ull unsigned long long
#define PI acos(-1.0)
#define eps 1e-12
#define initz(x) memset(x,0,sizeof(x))
#define initm(x) memset(x,0x3f,sizeof(x))
#define forn(i, n) for(int i = 0; i < (int) n; ++i)
#define for1(i, n) for(int i = 1; i <= (int) n; ++i)
#define fore(i, l, r) for(int i = (int) l; i <= (int) r; ++i)
#define rforn(i, n) for(int i = (int) n - 1; i>= 0; --i)
#define fi first
#define se second

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1 , 0, -1};

const int INF = 0x3f3f3f3f;
const int MAX_N = 50010;
const int MAX_M = 1 << 17;

typedef pair<ll, ll> P;

int mi[MAX_M], ma[MAX_M];
int c[MAX_N];

inline int left(int x) {
	return 2 * x;
}

inline int right(int x) {
	return 2 * x + 1;
}

void build(int idx, int lo, int hi)
{
	if(lo == hi) {
		mi[idx] = ma[idx] = c[lo];
		return;
	}
	int l_idx = left(idx);
	int r_idx = right(idx);
	int mid = (lo + hi) / 2;
	build(l_idx, lo, mid);
	build(r_idx, mid + 1, hi);
	mi[idx] = min(mi[l_idx], mi[r_idx]);
	ma[idx] = max(ma[l_idx], ma[r_idx]);
}

void query(int idx, int l, int r, int ql, int qr, int &mic, int &mac)
{
	if (ql > r || qr < l)
	{
		return;
	}
	if (ql <= l && r <= qr)
	{
		mic = min(mic, mi[idx]);
		mac = max(mac, ma[idx]);
		return;
	}

	int m = (l + r) >> 1;
	int l_idx = left(idx);
	int r_idx = right(idx);
	if (ql <= m)
	{
		query(l_idx, l, m, ql, qr, mic, mac);
	}

	if (qr > m)
	{
		query(r_idx, m + 1, r, ql, qr, mic, mac);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
#endif
	//---------------------------------------------
	// YOUR CODE
	initz(mi);
	initz(ma);
	initz(c);
	int n, m;
	scanf("%d %d", &n, &m);
	forn(i, n)
	{
		scanf("%d", &c[i]);
	}
	build(1, 0, n - 1);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		int mic, mac;
		mic = ma[1];
		mac = mi[1];
		query(1, 0, n - 1, a - 1, b - 1, mic, mac);
		printf("%d\n", mac - mic);
	}

//---------------------------------------------
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
