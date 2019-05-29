//floyd
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

// #define c11
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
const int MAX_M = 500;

int d[MAX_M][MAX_M];
int tmp[MAX_M];

void floyd(int n) {
  for1(k, n) {
    for1(i, n) {
      for1(j, n) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
    }
  }
}

int main() {
  memset(d, 0x3f, sizeof(d));
  int n, m;
  scanf("%d%d", &n, &m);
  while(m--) {
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i){
      scanf("%d", &tmp[i]);
      for(int j = 0; j < i; ++j) {
        d[tmp[i]][tmp[j]] = 1;
        d[tmp[j]][tmp[i]] = 1;
      }
    }
    floyd(n);
  }

  int ans, sum;
  ans = INF;
  for1(i, n) {
    sum = 0;
    for1(j, n) {
      if (i == j) continue;
      sum += d[i][j];
    }
    ans = min(ans, sum);
  }
  printf("%d\n", ans * 100 / (n - 1));
  return 0;
}