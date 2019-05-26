//floyd
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
#define initm(x) memset(x,0x7f,sizeof(x))
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
const int MAX_M = 5000;

typedef pair<int, int> P;

int d[MAX_N][MAX_N];
int m;

void floyd() {
  for (int k = 0; k < m; ++k) {
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < m; ++j) {
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
}

int main() {
  int n, a, b, c;
  while (scanf("%d", &n) != EOF && n) {
    memset(d, 0x3f, sizeof(d));
    m = 0;
    while (n--) {
      scanf("%d%d%d", &a, &b, &c);
      d[a][b] = d[b][a] = c;
      m = max(m, max(a + 1, b + 1));
    }
    floyd();
    int ans, p, tmp;
    p = 0;
    ans = INF;
    for (int i = 0; i < m; ++i) {
      tmp = 0;
      for (int j = 0; j < m; ++j) {
        if (i == j) continue;
        tmp += d[i][j];
        if (tmp >= INF) break;
      }
      if (tmp < ans) {
        ans = tmp;
        p = i;
      }
    }
    printf("%d %d\n", p, ans);
  }
  return 0;
}
