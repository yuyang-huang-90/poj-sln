// greedy
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
const int MAX_N = 100000 + 16;
;
const int MAX_M = 5000;

double s;
int n, k;

struct Jewel {
  int v, w;
  int id;
  bool operator<(const Jewel &other) const {
    return v - s * w > other.v - s * other.w;
  }
};
Jewel jewel[MAX_N];
int ids[MAX_N];

bool C(double mid) {
  s = mid;
  sort(jewel, jewel + n);
  double total_v = 0, total_w = 0;
  for (int i = 0; i < k; ++i) {
    total_v += jewel[i].v;
    total_w += jewel[i].w;
  }
  return total_v / total_w > mid;
}

int main() {

  cin >> n >> k;
  double max_s = 0;
  forn(i, n) {
    cin >> jewel[i].v >> jewel[i].w;
    jewel[i].id = i + 1;
    max_s = max(max_s, (double)jewel[i].v / jewel[i].w);
  }

  double lb = 0;
  double ub = max_s;
  for (int i = 0; i < 50; ++i) {
    double mid = (lb + ub) / 2;
    if (C(mid)) {
      lb = mid;
    } else {
      ub = mid;
    }
  }
  for (int i = 0; i < k; ++i)
  {
    ids[i] = jewel[i].id;
  }
  sort(ids, ids + k);
  copy(ids, ids + k, ostream_iterator<int>(cout, " "));

  return 0;
}
