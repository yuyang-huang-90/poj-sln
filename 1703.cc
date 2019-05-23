// uf
#include <algorithm>
#include <bitset>
#include <cctype>
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
#define initm(x) memset(x, 0x7f, sizeof(x))
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rforn(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define fi first
#define se second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const int INF = 0x7f7f7f7f;
const int MAX_N = 300000;
const int MAX_M = 5000;

typedef pair<int, int> P;

int parent[MAX_N];

int find(int a) {
  if (a == parent[a]) {
    return a;
  }
  return parent[a] = find(parent[a]);
}

void merge(int a, int b) { parent[find(a)] = find(b); }

int main() {
  int t, n, m,a,b;
  cin >> t;
  while (t--) {
    scanf("%d%d", &n, &m);
    fore(i, 1, (n << 1)) { parent[i] = i; }
    while (m--) {
      char op[3];
      scanf("%s%d%d", op, &a, &b);
      if (op[0] == 'A') {
        if(find(a) == find(b)) {
          printf("In the same gang.\n");
        } else if(find(a) == find(b+n)) {
          printf("In different gangs.\n");
        } else {
          printf("Not sure yet.\n");
        }
      } else {
        merge(a, b+n);
        merge(b, a+n);
      }
    }
  }
  return 0;
}
