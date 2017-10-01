//greedy
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>

const int MAX_LEN = 100;

int main() {
	int n;
	scanf("%d", &n);
	int a[MAX_LEN];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	std::sort(a, a + n);
	double ret = a[n-1];
	for (int j = n - 2; j >=0; --j) {
		ret = 2 * sqrt(ret * a[j]);
	}
	printf("%.3f\n", ret);
	return 0;
}
