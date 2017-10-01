#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstring>
#include<cstdio>

const int MAX_SIZE = 1000001;


int main() {
	int dp[MAX_SIZE];
	int n;
	scanf("%d", &n);
	dp[0] = 0;
	dp[1] = 1;
	//dp[2] = 2;
	for (int i = 2; i <=n ;i++) {
		if (i & 0x1) {
			dp[i] = dp[i - 1];
		} else {
			dp[i] = (dp[i >> 1] + dp[i - 1]) % 1000000000;
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}
