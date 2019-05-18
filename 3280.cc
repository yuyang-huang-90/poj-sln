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
const int MAX_N = 100;
const int MAX_M = 50005;

int cost[32];
int dp[2048][2048];

int main() {
	int N, M;
	cin >> N >> M;
	string s;
	cin >> s;
	for (int i = 0; i < N; ++i)
	{
		char c;
		int add_cost, delete_cost;
		cin >> c >> add_cost >> delete_cost;
		cost[c - 'a'] = min(add_cost, delete_cost);
	}
	for (int i = M - 1; i >= 0; --i)
	{
		for (int j = i + 1; j < M; ++j)
		{
			dp[i][j] = min(	dp[i + 1][j] + cost[s[i] - 'a'], dp[i][j - 1] + cost[s[j] - 'a']);
			if (s[i] == s[j])
			{
				dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
			} 
		}
	}
 
	cout << dp[0][M - 1] << endl;
	return 0;
}
