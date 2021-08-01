#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>

using namespace std;
#define cls(x) memset(x, 0, sizeof(x))

const int MAX = 10000;
const int N = 2000;

int num[N][N];
int s;

int lowbit(int x) { return x & (-x); }
void update(int x, int y, int v) {
	for (int i = x; i <= s; i += lowbit(i))
		for (int j = y; j <= s; j += lowbit(j))
			num[i][j] += v;
}
int query(int x, int y) {
	int ans = 0;
	for (int i = x; i > 0; i -= lowbit(i))
		for (int j = y; j > 0; j -= lowbit(j))
			ans += num[i][j];
	return ans;
}

int main() {
	int p, x1, x2, y1, y2, tmp;
	while (scanf("%d", &p)) {
		if (p == 0)
			scanf("%d", &s);
		if (p == 3)
			return 0;
		if (p == 1) {
			scanf("%d%d%d", &x1, &y1, &tmp);
			x1++;
			y1++;
			update(x1, y1, tmp);
		} else if (p == 2) {
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			x1++;
			y1++;
			x2++;
			y2++;
			int zans = query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) +
				query(x1 - 1, y1 - 1);
			printf("%d\n", zans);
		}
	}
}
