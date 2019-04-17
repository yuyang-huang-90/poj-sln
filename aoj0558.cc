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

#define c11
#ifdef c11
#include<unordered_set>
#include<unordered_map>
#endif

using namespace std;
typedef long long ll;
#define ull unsigned long long
#define PI acos(-1.0)
#define eps 1e-12
#define cls(x) memset(x,0,sizeof(x))
#define forn(i, n) for(int i = 0; i < (int) n; ++i)
#define for1(i, n) for(int i = 1; i <= (int) n; ++i)
#define fore(i, l, r) for(int i = (int) l; i <= (int) r; ++i)
#define rforn(i, n) for(int i = (int) n - 1; i>= 0; ++i)

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1 , 0, -1};

const int INF = 0x3f3f3f3f;
const int SZ = 1005;

int h, w, n;

char maze[SZ][SZ];
int dist[SZ][SZ];
int cx, cy;

int bfs(char target) {
  forn(i, h) {
    forn(j, w) {
      dist[i][j] = INF;
    }
  }
  dist[cx][cy] = 0;
  queue<pair<int,int>> q;
  q.push({cx, cy});
  while(!q.empty()) {
    auto cur = q.front(); q.pop();
    if(maze[cur.first][cur.second] == target) {
      cx = cur.first;
      cy = cur.second;
      return dist[cx][cy];
    }
    for(int d = 0; d < 4; ++d) {
      int nx = cur.first + dx[d];
      int ny = cur.second + dy[d];
      if(0 <= nx && nx < h && 0 <= ny && ny < w && maze[nx][ny] != 'X' && dist[nx][ny] == INF){
        q.push({nx, ny});
        dist[nx][ny] = dist[cur.first][cur.second] + 1;
      }
    }
  }
  return -1;
}

int main() {
  cin >> h >> w >> n;
  forn(i, h) {
    forn(j, w) {
      cin >> maze[i][j];
      if(maze[i][j] == 'S') {
        cx = i;
        cy = j;
      }
    }
  }
  int ret = 0;
  for1(t,n) {
    ret += bfs('0' + t);
  }
  cout << ret << endl;
	return 0;
}
