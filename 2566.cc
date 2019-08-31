//two pointer
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
const int MAX_N = 30;
const int MAX_M = 100050;

typedef pair<int, int> P;

P s[MAX_M];

int abs(int x) {
  if (x >= 0) return x;
  return -x;
}

int main() {
  int n, k, a;
  while (scanf("%d%d", &n, &k) != EOF && n) {
    s[0].first = 0;
    s[0].second = 0;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a);
      s[i].first = s[i - 1].first + a;
      s[i].second = i;
    }
    sort(s, s + n + 1);
    while (k--) {
      int t, tmp;
      int ans, p, q;
      ans = 2000000001;
      scanf("%d", &t);

      int i = 0, j = 1;
      while (i < j && j <= n) {
        tmp = s[j].first - s[i].first;
        if (abs(tmp - t) < abs(ans - t)) {
          ans = tmp;
          p = i;
          q = j;
        }

        if (tmp == t) {
          break;
        } else if (tmp > t) {
          ++i;
          if (i == j) ++j;
        } else if (tmp < t) {
          ++j;
        }
      }
      p = s[p].second;
      q = s[q].second;
      printf("%d %d %d\n", ans, min(p, q) + 1, max(p, q));
    }
  }
	return 0;
}
