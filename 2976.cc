// greedy
//
#include <algorithm>
#include <bitset>
#include <cctype>
#include <iomanip>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
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
const int MAX_N = 50000 + 16;
const int MAX_M = 5000;

double x;
int n, k;

struct Test {
  int a, b;
  bool operator<(const Test &other) const {
    return a - x * b > other.a - x * other.b;
  }
};

Test test[MAX_M];

bool C(double mid) {
  x = mid;
  sort(test, test + n);
  double total_a = 0, total_b = 0;
  for (int i = 0; i < n - k; ++i) {
    total_a += test[i].a;
    total_b += test[i].b;
  }
  return total_a / total_b > mid;
}

int main() {
  while (cin >> n >> k && (n || k)) {
    for (int i = 0; i < n; ++i) {
      cin >> test[i].a;
    }
    for (int i = 0; i < n; ++i) {
      cin >> test[i].b;
    }

    double lb = 0;
    double ub = 1;
    while (abs(ub - lb) > eps) {
      double mid = (lb + ub) / 2;
      if (C(mid)) {
        lb = mid;
      } else {
        ub = mid;
      }
    }

    cout << fixed << setprecision(0) << lb * 100 << endl;
  }
  return 0;
}
