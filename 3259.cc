//bellman ford
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>

using namespace std;
typedef long long ll;
#define cls(x) memset(x,0,sizeof(x))

int dis[1001];
struct edge {
	int x;
	int y;
	int len;
} e[3000];


const int MAX = 100000;

bool relax(edge &e, bool cond) {
	bool change = 0;
	if (dis[e.x] + e.len < dis[e.y]){
		dis[e.y] = dis[e.x] + e.len;
		change = 1;
	}
	if (cond && dis[e.y] + e.len < dis[e.x]){
		dis[e.x] = dis[e.y] + e.len;
		change = 1;
	}
	return change;
}

bool bellman_ford(int n, int m, int w) {
	for (int times = 0; times < n; ++times) {
		bool NotOk = 0;
		for (int i = 0; i < m + w; ++i) {
			if (relax(e[i], i < m)) NotOk = 1;
		}
		if (!NotOk) return true;
	}
	return false;
}

int main() {
	int c, N, M, W;
	cin >> c;
	while (c--) {
		cin >> N >> M >> W;
		dis[N] = 0;
		for (int i = 1; i < N; ++i) {
			dis[i] = MAX;
		}
		for (int i = 0; i < M; ++i) {
			scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].len);
		}
		for (int i = M; i < M + W; ++i) {
			scanf("%d %d %d", &e[i].x, &e[i].y, &e[i].len);
			e[i].len *= -1;
		}
		if (bellman_ford(N, M, W)) puts("NO");
		else puts("YES");

	}
	return 0;
}
