#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstring>
#include<cstdio>

const int MAX_N = 10010;
const int MAX_K = 110;
int dp[MAX_N][MAX_K];

int mod(int m, int k){
	if(m>=0)
		return m % k;
	return ((-m/k + 1)*k + m) % k;
}


int main() {
	freopen("input.txt","r",stdin);
	int a[MAX_N];
	int n, k;
	memset(dp, 0 , sizeof(dp));
	memset(a, 0, sizeof(a));
	scanf("%d %d",&n, &k);
	for (int i = 0; i < n ; i++) {
		scanf("%d", &a[i]);
	}
	dp[0][mod(a[0], k)] = 1;
	
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (dp[i-1][j]) {
				dp[i][mod(j + a[i], k)] = 1;
				dp[i][mod(j - a[i], k)] = 1;
			}
		}
	}

	if (dp[n-1][0]) {
		printf("Divisible\n");
	} else {
		printf("Not divisible\n");
	}
	return 0;
}
