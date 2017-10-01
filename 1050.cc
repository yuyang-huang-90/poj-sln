//dp
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define MAX 110

int data[MAX][MAX];

int max_array(int *a, size_t n) {
	int dp[MAX];
	memset(dp, -200, sizeof(dp));
	dp[0] = a[0];
	int max_sum = dp[0];
	for (int i = 1; i < n; i++) {
		dp[i] = std::max(a[i], dp[i-1] + a[i]);
		max_sum = std::max(max_sum, dp[i]);
	}
	return max_sum;
}

int main() {
	size_t n;
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> data[i][j];
		}
	}

	int tmp_sum[MAX];
	int max_matrix = data[0][0];
	for (int top_line = 0; top_line < n; top_line++) {
		memset(tmp_sum, 0, sizeof(tmp_sum));
		for (int end_line = top_line; end_line < n; end_line++) {
			for (int k = 0; k < n; k++){
				tmp_sum[k] += data[end_line][k];
			}
			max_matrix = std::max(max_matrix, max_array(tmp_sum, n));
		}
	}
	std::cout << max_matrix << std::endl;
	return 0;
}
