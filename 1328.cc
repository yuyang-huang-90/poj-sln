//greedy
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>


struct segment {
	double left;
	double right;
};

struct pt {
	int x;
	int y;
};

int n,d;

segment seg[1000];
pt island[1000];


bool cmp(const segment &a, const segment &b){
	if(a.left == b.left)
		return a.right < b.right;
	return a.left < b.left;
}

int solve() {
	for (int i = 0; i < n; ++i) {
		if (island[i].y > d) return -1;
		double delta = sqrt(d * d - island[i].y * island[i].y);
		seg[i].left = island[i].x - delta;
		seg[i].right = island[i].x + delta;
	}
	std::sort(seg, seg + n, cmp);
	int ret=1;
	double cur = seg[0].right;
	for(int i=1; i<n; ++i){
		if(seg[i].left > cur){
			ret++;
			cur = seg[i].right;
		}
		else if(seg[i].right < cur)
			cur = seg[i].right;
	}
	return ret;
}

int main() {
	int count = 1;
	while (1) {
		scanf("%d %d", &n, &d);
		if ( n == 0 && d == 0) break;
		for (int i = 0; i <  n; ++i) {
			scanf("%d %d", &island[i].x, &island[i].y);
		}
		int ret = solve();
		printf("Case %d: %d\n", count++, ret);
	}
	return 0;
}
