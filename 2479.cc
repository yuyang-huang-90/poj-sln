//dp
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>


const int MAX_LEN = 50010;
int data[MAX_LEN];
int dp[MAX_LEN];
int max_end[MAX_LEN];
int max_start[MAX_LEN];

int main() {
	int t;
	std::cin >> t;
	while (t-- > 0) {
		int n;
		scanf("%d", &n);
		for(int i = 0; i < n; i ++)
			scanf("%d", &data[i]);
		//calc_max_start
		dp[0] = data[0];
		max_end[0] = dp[0];
		for (int i = 1; i < n; i++) {
			dp[i] = std::max(data[i], dp[i-1] + data[i]);
			max_end[i] = std::max(dp[i], max_end[i-1]);
		}
		//calc_max_end
		dp[n-1] = data[n-1];
		max_start[n-1] = dp[n-1];
		for (int j = n - 2; j >= 0; j--) {
			dp[j] = std::max(data[j], data[j] + dp[j+1]);
			max_start[j] = std::max(dp[j], max_start[j+1]);
		}
		int ans = -999999;
		for(int k = 0; k < n - 1; k++)
			ans = std::max(ans, max_end[k] + max_start[k+1]);
		printf("%d\n", ans);
	}

	return 0;
}
