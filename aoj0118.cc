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


char table[SZ][SZ];

int h, w;

bool is_valid(int x, int y, char chr) {
  return x >= 0 && x < h && y >= 0 && y < w && table[x][y] == chr;
}

void dfs(int x, int y, char chr) {
  if(!is_valid(x,y,chr)) return;
  table[x][y] = '.';
  dfs(x+1,y,chr);
  dfs(x-1,y,chr);
  dfs(x,y+1,chr);
  dfs(x,y-1,chr);
}

int main() {
  while(1) {
    cin >> h >> w;
    if(h == 0 && w == 0) break;
    for(int i = 0; i < h; ++i) {
      for(int j = 0; j < w; ++j) {
        cin >> table[i][j];
      }
    }
    int ret = 0;
    for(int i = 0; i < h; ++i) {
      for(int j = 0; j < w; ++j) {
        if(table[i][j] != '.') {
          dfs(i, j, table[i][j]);
          ret++;
        }
      }
    }
    cout << ret << endl;
  }
	return 0;
}
