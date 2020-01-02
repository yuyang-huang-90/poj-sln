//bigraph
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
const int MAX_N = 500;
const int MAX_M = 500;

int match[MAX_N];
int d[MAX_N][MAX_N];
int e[MAX_N][MAX_N];
int checked[MAX_N];

typedef pair<ll, ll> P;

int C, K, M;
int n1, n2;

bool dfs(int u) {
    forn(v, n2) {
        if (e[u][v] > 0 && !checked[v]) {
            checked[v] = 1;
            int w = match[v];
            if (w < 0 || dfs(w)) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

bool hungarin() {
    initn1(match);
    forn(i, n1) {
        initz(checked);
        if (!dfs(i)) return false;
    }
    return true;
}

void floyd(int n) {
    forn(k, n) {
        forn(i, n) {
            forn(j, n) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}

void build_graph(int g) {
    initz(e);
    forn(i, C) {
        forn(j, K) {
            if (d[K + i][j] <= g) {
                for (int k = M * j; k < M * (j + 1); ++k) {
                    e[i][k] = 1;
                }
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
//---------------------------------------------
// YOUR CODE
    scanf("%d%d%d", &K, &C, &M);
    int n = K + C;
    forn(i, n) {
        forn(j, n) {
            scanf("%d", &d[i][j]);
            if (!d[i][j]) d[i][j] = INF;
        }
    }
    floyd(n);
    n1 = C, n2 = K * M;
    floyd(K + C);
    int l, r, m;
    l = 0;
    r = (K + C) * 200;
    while (l + 1 < r) {
        m = (l + r) >> 1;
        build_graph(m);
        if (hungarin()) {
            r = m;
        } else {
            l = m;
        }
    }
    cout << r << endl;

//---------------------------------------------
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
