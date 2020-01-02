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
const int MAX_N = 120;
const int MAX_M = 1010;

typedef pair<ll, ll> P;


vector<int> e[1010];
bool checked[1010];
int match[1010];
int n1;

int n, m;
int d[110][110];

int p[1010], t[1010];

bool dfs(int u) {
    for (vector<int>::iterator it = e[u].begin(); it != e[u].end(); ++it) {
        int v = *it;
        if (!checked[v]) {
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

int hungarin() {
    initn1(match);
    int ans = 0;
    forn(i, n1) {
        initz(checked);
        if (dfs(i)) ans++;
    }
    return ans;
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


int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
//---------------------------------------------
// YOUR CODE
    while (scanf("%d%d%d", &n, &m, &n1) != EOF && n) {
        memset(d, 0x3f, sizeof(d));
        for (int i = 0; i < n; ++i) d[i][i] = 0;
        for (int i = 0; i < m; ++i) {
            int u, v, c;
            scanf("%d%d%d", &u, &v, &c);
            d[u][v] = d[v][u] = c;
        }
        floyd(n);
        for (int i = 0; i < n1; ++i) {
            scanf("%d%d", &p[i], &t[i]);
            e[i].clear();
        }
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < n1; ++j) {
                if (i == j) continue;
                if (t[i] + d[p[i]][p[j]] <= t[j]) {
                    e[i].push_back(j);
                }
            }
        }
        printf("%d\n", n1 - hungarin());
    }
//---------------------------------------------
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
