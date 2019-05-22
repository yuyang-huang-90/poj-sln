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
const int MAX_N = 500;
const int MAX_M = 40020;

int d[MAX_M];

struct B{
  int h, c, a;
  bool operator<(const B& b) const {
    return a < b.a;
  }
}b[MAX_N];

typedef pair<int, int> P;

int main() {
  int n,  H = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &b[i].h, &b[i].a, &b[i].c);
    H = max(H, b[i].a);
  }

  sort(b, b + n);

  memset(d, -1, sizeof(d));
  d[0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= b[i].a; ++j) {
      if (d[j] != -1) {
        d[j] = b[i].c;
      } else if (j >= b[i].h && d[j - b[i].h] > 0) {
        d[j] = d[j - b[i].h] - 1;
      }
    }
  }
  for (int i = H; i >= 0; --i) {
    if (d[i] != -1) {
      printf("%d\n", i);
      break;
    }
  }
  return 0;
}
