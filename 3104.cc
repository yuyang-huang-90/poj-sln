//binary search
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
const int MAX_M = 100000 + 16;

typedef pair<int, int> P;

int N, M;

ll money[MAX_M];

bool C(ll d) {
  int period = 1;
  ll cost = 0;
  forn(i, N) {
    cost += money[i];
    if(cost > d) {
      cost = money[i];
      ++period;
    }
  }
  if (period > M) {
    return true;
  }
  return false;
}

int main() {
  cin >> N >> M;
  ll max_elem = 0;
  ll accum = 0;
  forn(i, N) {
    cin >> money[i];
    accum += money[i];
    max_elem = max(max_elem, money[i]);
  }
  ll l = max_elem, r = accum;
  while(l < r) {
    ll m = (l + r) / 2;
    if(C(m)) {
      l = m + 1;
    } else {
      r = m;
    }
  }

  cout << l << endl;

	return 0;
}
