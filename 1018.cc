#include<cstdio>
#include<algorithm>
#include<cstring>

#define MAX_SIZE 1100
#define LEVEL 110

int dp[LEVEL][MAX_SIZE];
int current_bw[110];
int current_price[110];

void solve(void) {
	int n, m;
	int bw, price, maxbw = -1;
	memset(dp, -1, sizeof(dp));
	scanf("%d",&n);
	for (int t = 0; t < n; t++) {
		scanf("%d",&m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &bw, &price);
			//printf("%d %d ", bw, price);
			current_bw[i] = bw;
			current_price[i] = price;
			//printf("%d %d ", current_bw[i], current_price[i]);
			if (t == 0) {
				maxbw = std::max(maxbw, bw);
				dp[0][bw] = price;
				//printf(" (%d) ", maxbw);
			}
		}
		//printf("\n");
		if (t == 0) continue;
		for(int j = 0; j <= maxbw; j++) {
			if (dp[t-1][j] != -1) {
				for (int k = 0; k < m; k++) {
					int min_bw = std::min(j, current_bw[k]);
					if (dp[t][min_bw] == -1) {
						dp[t][min_bw] = dp[t-1][j] + current_price[k];
					} else {
						dp[t][min_bw] = std::min(dp[t][min_bw], dp[t-1][j] + current_price[k]);
					}
				}
			}
		}
	}
	//print_dp(maxbw);

	double r = 0;
	for (int i = 0; i <= maxbw; i++) {
		if (dp[n-1][i] != -1) {
			//printf("bw:%d  price:%d\n", i, dp[n-1][i]);
			//printf("%f\n", 1.0 * i / dp[n-1][i]);
			r = std::max(r, 1.0 * i / dp[n-1][i]);
		}
	}
	printf("%.3f\n", r);
}

int main() {
	int t;
	scanf("%d",&t);
	while(t-- > 0) {
		solve();
	}
}
