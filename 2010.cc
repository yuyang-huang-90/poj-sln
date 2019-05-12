//priority_queue
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
const int MAX_N = 1e5 + 30;
const int MAX_M = 50005;
typedef pair<int, int> P;

P p[MAX_N];
ll low[MAX_N], high[MAX_N];

int main() {
  int n,c,f;
  scanf("%d%d%d", &n, &c, &f);
  int half = n / 2;
  forn(i, c) scanf("%d%d", &p[i].first, &p[i].second);
  sort(p, p + c);
  {
    ll sum = 0;
    priority_queue<ll>q;
    forn(i, half) {
      q.push(p[i].second);
      sum += p[i].second;
      low[i] = INF;
    }
    for(int i = half; i < c; ++i) {
      low[i] = sum;
      q.push(p[i].second);
      sum += p[i].second - q.top();
      q.pop();
    }
  }
  {
    ll sum = 0;
    priority_queue<ll>q;
    for(int i = c - 1; i >= c - half; --i) {
      q.push(p[i].second);
      sum += p[i].second;
      high[i] = INF;
    }
    for(int i = c - half - 1; i >= 0; --i) {
      high[i] = sum;
      q.push(p[i].second);
      sum += p[i].second - q.top();
      q.pop();
    }
  }

  int ans = -1;
  for (int i = c - 1 ; i >= 0 ; i--) {
    if (high[i] + low[i] + p[i].second <= f) {
      ans = p[i].first;
      break;
    }
  }
  cout << ans << endl;
	return 0;
}
