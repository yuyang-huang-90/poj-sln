//binary search
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
const int MAX_M = 500005;

typedef pair<int, int> P;

int N, M, L;

int dist[MAX_M];

bool C(int d) {
  int prev = 0;
  for(int i = 1; i < N - M; ++i) {
		int current = prev + 1;
		while (current < N && dist[current] - dist[prev] < d) {
			++current;
		}
		if (current == N) {
			return false;
		}
		prev = current;
  }
  return true;
}

int main() {
  cin >> L >> N >> M;
  for1(i, N) {
    cin >> dist[i];
  }
  ++N;
  dist[N] = L;
  ++N;
  sort(dist, dist + N);
  int l = 0, r = L + 1;
  while(r - l > 1) {
    int m = (l + r) / 2;
    if(C(m)) {
      l = m;
    } else {
      r = m;
    }
  }

  cout << l << endl;

	return 0;
}
