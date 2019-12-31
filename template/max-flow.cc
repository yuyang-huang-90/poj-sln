//max flow
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

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX_N = 1200;
const int MAX_M = 5000;

typedef pair<ll, ll> P;


struct node {
    int to, cap, rev;

    node(int _to, int _cap, int _rev) : to(_to), cap(_cap), rev(_rev) {
    }
};

vector<node> G[MAX_N];
int vis[MAX_N];

void add_edge(int from, int to, int cap) {
    G[from].push_back(node(to, cap, G[to].size()));
    G[to].push_back(node(from, 0, G[from].size() - 1));
}

int dfs(int v, int t, int f) {
    if (v == t) return f;
    vis[v] = true;
    for (unsigned int i = 0; i < G[v].size(); i++) {
        node &e = G[v][i];
        if (!vis[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}


int max_flow(int s, int t) {
    int flow = 0;
    while (1) {
        memset(vis, 0, sizeof(vis));
        int f = dfs(s, t, INF);
        if (f == 0) return flow;
        flow += f;
    }
}

int main() {
    int t;
    int n, m;
    int Case = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i <= n; i++) G[i].clear();
        for (int i = 0; i < m; i++) {
            int x, y, c;
            scanf("%d%d%d", &x, &y, &c);
            add_edge(x, y, c);
        }
        printf("Case %d: %d\n", ++Case, max_flow(1, n));
    }
    return 0;
}