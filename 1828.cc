// greedy
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cstring>
#include<cstdio>

struct Point{
	int x,y;
};

bool cmp_pt(const Point &a, const Point &b) {
	if (a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}


Point pt[50000];

int main() {
	int n;
	while (1) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &pt[i].x, &pt[i].y);
		}
		std::sort(pt, pt + n, cmp_pt);
		int count = 1;
		int king_y = pt[n-1].y;
		for (int j = n - 2; j >=0; j--) {
			if(pt[j].x == pt[j + 1].x) continue;
			else if (pt[j].y > king_y) {
				king_y = pt[j].y;
				++count;
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
