//dp
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

/* #define c11 */
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
const int MAX_N = 1500;
const int MAX_M = 50005;

typedef pair<int, int> P;

struct Interval
{
	int starting_hour, ending_hour, efficiency;
	bool operator < (const Interval& i) const
	{
		return starting_hour < i.starting_hour;
	}
};

Interval interval[MAX_N];
int dp[MAX_N];

int main() {
  int n, m, r;
  cin >> n >> m>> r;
  forn(i, m) {
    cin >> interval[i].starting_hour >> interval[i].ending_hour >> interval[i].efficiency;
    interval[i].ending_hour += r;
  }
  sort(interval, interval + m);

  forn(i, m) {
    dp[i] = interval[i].efficiency;
    forn(j, i) {
      if(interval[j].ending_hour <= interval[i].starting_hour) {
        dp[i] = max(dp[i], dp[j] + interval[i].efficiency);
      }
    }
  }

  cout << *max_element(dp, dp + m) << endl;
	return 0;
}
