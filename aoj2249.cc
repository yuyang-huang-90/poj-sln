//shortest path
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

#define c11
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
const int MAX_N = 30;
const int MAX_M = 15000;

typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P> > pq;

struct Edge{
  Edge() {}
  Edge(int vv, int cc, int ww): v(vv), c(cc), w(ww) {}
  int v, c, w;
};

vector<Edge> edges[MAX_M];
int pre[MAX_M];
int d[MAX_M];

void dijkstra(int n, int s) {
  initm(d);
  d[s] = 0;
  pq.push({d[s], s});
  while (!pq.empty()) {
    int u, v, c, m;
    m = pq.top().first;
    u = pq.top().second;
    pq.pop();
    if (m > d[u]) {
      continue;
    }
    for (auto it : edges[u]) {
      v = it.v;
      c = it.c;
      int t = d[u] + c;
      if (t < d[v]) {
        d[v] = t;
        pq.push({d[v], v});
        pre[v] = it.w;
      } else if (t == d[v]) {
        pre[v] = min(pre[v], it.w);
      }
    }
  }
}

int main() {
  int n, m, u, v, c, w;
  while (scanf("%d%d", &n, &m) != EOF && n) {
		for1(i, n) {
      edges[i].clear();
    }
		while(m--) {
		  scanf("%d%d%d%d", &u, &v, &c, &w);
      edges[u].push_back(Edge(v, c, w));
      edges[v].push_back(Edge(u, c, w));	
		}
		dijkstra(n, 1);
    int ans = 0;
    for (u = 2; u <= n; ++u) {
      ans += pre[u];
    }
    printf("%d\n", ans);
	}
  return 0;
}
