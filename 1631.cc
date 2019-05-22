//dp
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
#define rforn(i, n) for(int i = (int) n - 1; i>= 0; --i)
#define fi first
#define se second

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1 , 0, -1};

const int INF = 0x7f7f7f7f;
const int MAX_N = 50005;
const int MAX_M = 5000;

int ed[MAX_N];
int a[MAX_N];

typedef pair<int, int> P;

int main() {
	int T,n;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		forn(i, n) {
			scanf("%d", &a[i]);
		}
		initz(ed);
		int len = 0;
		forn(i, n) {
			int idx = lower_bound(ed, ed + len, a[i]) - ed;
			if(idx == len) {
				ed[len++] = a[i];
			} else {
				ed[idx] = a[i];
			}
		}
		printf("%d\n", len);
	}
	return 0;
}
