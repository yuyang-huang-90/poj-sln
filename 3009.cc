//dfs
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>

using namespace std;
typedef long long ll;
#define cls(x) memset(x,0,sizeof(x))


const int INF = 0x3f3f3f3f;
const int SZ = 100;
int matrix[SZ][SZ];
int m, n;
int start_x, start_y;
int end_x, end_y;
int ret;

void dfs(int x, int y, int cnt) {
  if(matrix[x][y] == 3) {
    if(cnt < ret) {
      ret = cnt;
    }
    return;
  }
  if(cnt >= 10) {
    return;
  }
  /* for(int i = 0; i < m; ++i) { */
  /*   for(int j = 0; j < n; ++j) { */
  /*     cout << matrix[i][j] << " "; */
  /*   } */
  /*   cout << endl; */
  /* } */
  int dir[4][2] = {1,0,-1,0,0,-1,0,1};
  for(int d = 0; d < 4; ++d) {
    int nx = x;
    int ny = y;
    //cout << d << "-" << cnt << endl;
    while(1) {
      //cout << nx << "," << ny << endl;
      if(nx<0||ny < 0||nx >m-1||ny > n-1||matrix[nx][ny] == 1)
        break;
      if(matrix[nx][ny] == 3) {
        cnt++;
        if(cnt < ret) {
          ret = cnt;
        }
        return;
      }
      nx += dir[d][0];
      ny += dir[d][1];
    }

    if(nx < 0||ny <0||nx > m-1||ny > n-1||(nx == x+dir[d][0]&&ny == y+dir[d][1])) 
      continue;
    matrix[nx][ny] = 0;
    cnt++;
    /* for(int i = 0; i < m; ++i) { */
    /*   for(int j = 0; j < n; ++j) { */
    /*     cout << matrix[i][j] << " "; */
    /*   } */
    /*   cout << endl; */
    /* } */
    dfs(nx - dir[d][0], ny - dir[d][1], cnt);
    matrix[nx][ny] = 1;
    cnt--;
  }


}

int main() {
  m = -1;
  n = -1;
  while(1) {
    cin >> m >> n;
    if(m == 0&& n == 0) break;
    for(int i = 0; i < m; ++i) {
      for(int j = 0; j < n; ++j) {
        cin >> matrix[i][j];
        if(matrix[i][j] == 2) {
          start_x = i;
          start_y = j;
        } else if(matrix[i][j] == 3) {
          end_x = i;
          end_y = j;
        }
      }
    }
    ret = INF;
    dfs(start_x, start_y, 0);
    if(ret == INF) {
      cout << -1 << endl;
    } else {
      cout << ret << endl;;
    }

  }
	return 0;
}
