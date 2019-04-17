//bfs
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

typedef pair<int, int> P;

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1 , 0, -1};

const int INF = 0x7f7f7f7f;
const int MAX_N = 500;
const int MAX_M = 50005;
int X[MAX_M], Y[MAX_M], T[MAX_M];
int M;

int maze[MAX_N][MAX_N];
int dist[MAX_N][MAX_N];

int bfs() {
  if(maze[0][0] == 0) return -1;
  queue<P> q;
  q.push(P(0,0));
  dist[0][0] = 0;
  while(!q.empty()) {
    P p = q.front(); q.pop();
    int x = p.first;
    int y = p.second;
    if(maze[x][y] == INF) return dist[x][y];
    forn(i,4) {
      int nx = x + dx[i], ny = y + dy[i];
      if(0 <= nx && 0 <= ny && dist[nx][ny] == INF && dist[x][y] + 1 < maze[nx][ny]){
        q.push(P(nx, ny));
        dist[nx][ny] = dist[x][y] + 1;
      }
    }
  }
  return -1;
}

void solve() {
  initm(maze);
  initm(dist);
  forn(i, M) {
    maze[X[i]][Y[i]] = min(maze[X[i]][Y[i]], T[i]);
    forn(d, 4) {
      int nx = X[i] + dx[d], ny = Y[i] + dy[d];
      if(0 <= nx && 0 <= ny) {
        maze[nx][ny] = min(maze[nx][ny], T[i]);
      }
    }
  }
  cout << bfs() << endl;
}

int main() {
  cin >> M;
  forn(i, M) {
    scanf("%d %d %d", &X[i], &Y[i], &T[i]);
  }
  solve();
	return 0;
}
