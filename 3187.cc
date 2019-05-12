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

int num[20];
int c[20][20];

typedef pair<int, int> P;

bool judge(int n, int sum) {
  for1(i, n) {
    c[n][i] = num[i];
  }
  for(int i = n-1; i >= 1; i--)
    for(int j = 1; j <= i; j++)
      c[i][j] = c[i+1][j] + c[i+1][j+1];
  return c[1][1] == sum;
}

int main() {
  int N, M;
  while(scanf("%d%d", &N, &M) != EOF) {
    for1(i,N) {
      num[i] = i;
    }
    do {
      if(judge(N, M)) {
        for1(i, N) {
          if(i > 1) cout << " ";
          cout << num[i];
        }
        cout << endl;
        break;
      }
    } while(next_permutation(num +1 , num + 1 + N));
  }
	return 0;
}
