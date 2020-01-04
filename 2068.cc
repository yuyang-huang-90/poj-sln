//nim
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
#define initn1(x) memset(x,-1,sizeof(x))
#define initm(x) memset(x,0x3f,sizeof(x))
#define forn(i, n) for(int i = 0; i < (int) n; ++i)
#define for1(i, n) for(int i = 1; i <= (int) n; ++i)
#define fore(i, l, r) for(int i = (int) l; i <= (int) r; ++i)
#define rforn(i, n) for(int i = (int) n - 1; i>= 0; --i)
#define fi first
#define se second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX_N = 20;
const int MAX_M = 1 << 13;

typedef pair<ll, ll> P;

int m[MAX_N];
int d[MAX_M][MAX_N];

int n;

int dp(int s, int u) {
    if (d[s][u] != -1) return d[s][u];
    if (s == 1) return d[s][u] = 0;
    int v = (u + 1) % n;
    for (int i = 1; i <= m[u] && i < s; ++i) {
        if (dp(s - i, v) == 0) {
            return d[s][u] = 1;
        }
    }
    return d[s][u] = 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
//---------------------------------------------
// YOUR CODE
    int s;
    while (scanf("%d", &n) != EOF && n) {
        n <<= 1;
        initn1(d);
        scanf("%d", &s);
        forn(i, n) {
            scanf("%d", &m[i]);
        }
        printf("%d\n", dp(s, 0));
    }

//---------------------------------------------
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
