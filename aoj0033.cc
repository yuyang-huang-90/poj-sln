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

int main() {
  int total = 1 << 10;
  int n;
  cin >> n;
  int a[10];
  while(n-- > 0) {
    for(int i = 0; i < 10; ++i) {
      cin >> a[i];
    }
    bool flag;
    for(int p = 0; p < total; ++p) {
      int cur = p;
      int pre_left = -1, pre_right = -1;
      flag = true;
      for(int i = 0; i < 10; ++i) {
        if((cur >> i) & 1) {
          //left
          //cout << a[i] << endl;
          if(a[i] > pre_left) {
            pre_left = a[i];
          } else {
            flag = false;
            break;
          }
        } else {
          // right
          if(a[i] > pre_right) {
            pre_right = a[i];
          } else {
            flag = false;
            break;
          }
        }
      }
      if(flag) break;
    }
    if(flag)  {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
	return 0;
}
