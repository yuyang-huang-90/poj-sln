//greedy
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
#define rforn(i, n) for(int i = (int) n - 1; i>= 0; ++i)
#define fi first
#define se second

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1 , 0, -1};

const int INF = 0x7f7f7f7f;
const int MAX_N = 100010;
const int MAX_M = 50005;

typedef pair<int, int> P;

P p[MAX_N];

bool cmp(P a, P b) {
  return a.first * b.second < a.second * b.first;
}

int main() {
  int n;
  scanf("%d", &n);
  forn(i, n) {
    scanf("%d %d", &p[i].fi, &p[i].se);
  }
  sort(p, p + n, cmp);
  ll ret = 0, t = 0;
  forn(i, n) {
    ret += t * p[i].se;
    t += 2 * p[i].fi;
  }
  cout << ret << endl;
	return 0;
}
