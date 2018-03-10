//dp
#include<vector>
#include<list>
#include<deque>
#include<queue>
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

using namespace std;
typedef long long ll;
#define cls(x) memset(x,0,sizeof(x))


const int INF = 0x3f3f3f3f;
const int SZ = 1200;

int data[SZ];
int dp[SZ];

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%d", &data[i]);
		}
		cls(dp);
		int ans = 1;
		dp[0] = 1;
		for (int e = 1; e < n; ++e) {
			int cur = 1;
			for (int s = e - 1; s >= 0; --s) {
				if (data[s] < data[e] && dp[s] >= cur) {
					cur = dp[s] + 1;
				}
			}
			dp[e] = cur;
			ans = max(ans, cur);
		}
		cout << ans << endl;
	}
	return 0;
}
