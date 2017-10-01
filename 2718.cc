#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstring>
#include<limits>
#include<cstdio>
#include<cmath>

int d[10];

int calc_val(int *a, int start, int end) {
	int ret = 0;
	for (int i = start; i < end; ++i) {
		ret = ret * 10 + a[i];
	}
	return ret;
}

int solve(int num) {
	int ret = std::numeric_limits<int>::max();
	int mid =  num / 2;
	if (num == 2) return abs(d[0] - d[1]); //corner case : 0 ?
	do
	{
		if (d[0] == 0 || d[mid] == 0) continue;
		int l = calc_val(d, 0, mid);
		int r = calc_val(d, mid, num);
		ret = std::min(ret, abs(l-r));

	} while (std::next_permutation(d, d + num));
	return ret;
}

int main() {
	int n;
	char c;
	int i;
	scanf("%d", &n);
	getchar();
	while (n--) {
		i = 0;
		while ((c = getchar()) != '\n') {
			if (c == ' ') continue;
			d[i++] = c - '0';
		}
		printf("%d\n", solve(i));
	}

	return 0;
}
