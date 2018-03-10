//TYPE
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



const int MAXN = 110;
const int MAXW = 1200;

int dp[MAXN][MAXW];
int bw[MAXN];
int p[MAXN];
const int INF = 0x3f3f3f3f;


int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n;
		memset(dp,0x3f,sizeof(dp));
		int maxbw = -1;;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &m);
			for (int j = 1; j <= m; ++j) {
				scanf("%d %d",&bw[j], &p[j]);
				maxbw = max(maxbw, bw[j]);
			}
			if (i == 1) {
				for (int j = 1; j <=m; ++j) {
					dp[1][bw[j]] = p[j];
				}
				continue;
			}
			for (int w = 0; w <= maxbw; ++w) {
				if (dp[i-1][w] != INF) {
					for (int k = 1; k <= m; ++k) {
						if (dp[i-1][w] + p[k] < dp[i][min(w,bw[k])]) {
							dp[i][min(w,bw[k])] = dp[i-1][w] + p[k];
						}
					}
				}
			}
		}
		double ans = -1;
		for(int w = 0; w <= maxbw; w++) {
			if(dp[n][w] != INF) {
				ans = max(ans, (double)w / dp[n][w]);
			}
		}
		printf("%.3f\n", ans);
	}
	return 0;
}
