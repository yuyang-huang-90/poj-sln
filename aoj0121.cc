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
const int SZ = 100;

map<string, int> memo;

int direction[]={1,-1,4,-4};

void bfs() {
  queue<string> q;
  string cur = "01234567";
  memo[cur] = 0;
  q.push(cur);
  while(!q.empty()) {
    cur = q.front(); q.pop();
    int pos = 0;
    forn(i, 8) {
      if(cur[i] == '0') {
        pos = i;
        break;
      }
    }

    forn(d, 4) {
      int nxt = pos + direction[d];
      if(nxt >= 0 && nxt < 8 && !(pos == 3 && d == 0) && !(pos == 4 && d == 1)) {
        string update = cur;
        swap(update[pos], update[nxt]);
        if(memo.find(update) == memo.end()) {
          memo[update] = memo[cur] + 1;
          q.push(update);
        }
      }
    }
  }
}

int main() {
  bfs();
  string input;
  while(getline(cin, input)) {
    input.erase(remove(input.begin(), input.end(), ' '), input.end());
    cout << memo[input] << endl;
  }
	return 0;
}
