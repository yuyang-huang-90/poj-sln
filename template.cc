//TYPE
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
const int MAX_N = 30;
const int MAX_M = 5000;

int cost[MAX_N];
int dp[MAX_M][MAX_M];

typedef pair<int, int> P;

int main() {
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	forn(i, n) {
		char c, add_cost, del_cost;
		cin >> c >> add_cost >> del_cost;
		cost[c - 'a'] = min(add_cost, del_cost);
	}
	rforn(i, m) {
		for(int j = i + 1; j < m; ++j) {
			if(s[i] == s[j]) {
				dp[i][j] = min(dp[i][j], dp[i+1][j-1]);
			} else {
				dp[i][j] = min(dp[i+1][j] + cost[s[i] - 'a'], dp[i][j-1] + cost[s[j] - 'a']);
			}
		}
	}
	cout << dp[0][m-1] << endl;

	return 0;
}
