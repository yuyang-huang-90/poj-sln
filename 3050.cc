//search
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
#define first fi
#define second se

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1 , 0, -1};

const int INF = 0x7f7f7f7f;
const int MAX_N = 100;
const int MAX_M = 50005;

int m[5][5];
set<int> flag;

typedef pair<int, int> P;

void dfs(int x, int y, int k, int sum) {
  if(k == 5) {
    flag.insert(sum);
    return;
  }
  forn(d,4) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5) {
      dfs(nx, ny, k + 1, sum * 10 + m[nx][ny]);
    }
  }
}

int main() {
  forn(i, 5) {
    forn(j, 5) {
      cin >> m[i][j];
    }
  }

  forn(i, 5) {
    forn(j, 5) {
      dfs(i, j, 0, m[i][j]);
    }
  }
  cout << flag.size() << endl;
	return 0;
}
