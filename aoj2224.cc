//mst
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
#define initm(x) memset(x,0x7f,sizeof(x))
#define forn(i, n) for(int i = 0; i < (int) n; ++i)
#define for1(i, n) for(int i = 1; i <= (int) n; ++i)
#define fore(i, l, r) for(int i = (int) l; i <= (int) r; ++i)
#define rforn(i, n) for(int i = (int) n - 1; i>= 0; --i)
#define fi first
#define se second

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1 , 0, -1};

const int INF = 0x7f7f7f7f;
const int MAX_N = 30;
const int MAX_M = 50000;

typedef pair<int, int> P;

struct E{
  E() {}
  E(int uu, int vv, double cc): u(uu), v(vv), c(cc) {}
  bool operator > (const E& e) const {
    return c < e.c;
  }
  int u, v;
  double c;
};

int fa[MAX_M];

priority_queue<E, vector<E>, greater<E> > pq;

int find(int x) {
  if(x == fa[x]) return x;
  return fa[x] = find(fa[x]);
}

double Kruskal(int n) {
  for(int i = 1; i <= n; ++i) {
    fa[i] = i;
  }
  int cnt = 1;
  double ans = 0;

  while(cnt < n && !pq.empty()) {
    const E& e = pq.top();
    int u, v;
    double c;
    u = e.u;
    v = e.v;
    c = e.c;
    pq.pop();

    u = find(u);
    v = find(v);
    if(u == v) continue;
    fa[u] = v;
    ans += c;
    ++cnt;
  }
  return ans;
}

double x[MAX_M], y[MAX_M];

int main() {
	int n, m;
  double ans = 0;
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; ++i) {
    scanf("%lf%lf", &x[i], &y[i]);
  }
  while(m--) {
    int u, v;
    double c;
    scanf("%d%d", &u, &v);
    c = sqrt((x[u]-x[v])*(x[u]-x[v]) + (y[u]-y[v])*(y[u]-y[v]));
    ans += c;
    pq.push(E(u, v ,c));
  }
  ans -= Kruskal(n);
  printf("%.3f\n", ans);
	return 0;
}
