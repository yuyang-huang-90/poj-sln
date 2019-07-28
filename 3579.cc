// binary search
//
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

//#define c11
#ifdef c11
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;
typedef long long ll;
#define ull unsigned long long
#define PI acos(-1.0)
#define eps 1e-12
#define initz(x) memset(x, 0, sizeof(x))
#define initm(x) memset(x, 0x3f, sizeof(x))
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rforn(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define fi first
#define se second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const int INF = 0x3f3f3f3f;
const int MAX_N = 110000;
const int MAX_M = 5000;

int x[MAX_N];
int n;
int cn2 = 0;

bool C(int mid) {
  int cnt = 0;
  forn(i, n) {
    cnt += n + x - lower_bound(x + i, x + n, x[i] + mid);
  }
  return cnt > (cn2 >> 1);
}

int main() {
  while (scanf("%d", &n) == 1) {  
    forn(i,n) {
      scanf("%d", &x[i]);
    }

    sort(x, x + n);
    cn2 = (n * (n-1) ) / 2;
     int lb = 0, ub = 1000000001;
     while(ub - lb > 1) {
       int mid = (lb + ub) >> 1;
       if(C(mid)) lb = mid;
       else ub = mid;
     }
     printf("%d\n", lb);
  }

  return 0;
}
