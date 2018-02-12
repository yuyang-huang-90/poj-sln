// dp
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <set>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
#define cls(c) memset(c,0,sizeof(c))
const double eps = 1E-8;
const int dx[4]={1,0,0,-1};
const int dy[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;

struct Edge {
	int to, nxt;
};

const int N = 2000;
const int SZ = 20010;
Edge edge[SZ*2];
int head[SZ];
int idx;
int tsize[SZ];
int n;
int id = inf;

int minx = inf;

void add_edge(int u, int v) {
	edge[idx].to = v;
	edge[idx].nxt = head[u];
	head[u] = idx++;
}

int dfs(int u, int fa) {
	// count self
	tsize[u] = 1;
	// calc size
	for (int e = head[u]; e != 0; e = edge[e].nxt) {
		int v = edge[e].to;
		if (v == fa) continue;
		tsize[u] += dfs(v, u);
	}

	// calc delete
	int ans = n - tsize[u];
	for (int e = head[u]; e != 0; e = edge[e].nxt) {
		int v = edge[e].to;
		if (v == fa) continue;
		ans = max(ans, tsize[v]);
	}

	if (ans < minx) {
		minx = ans;
		id = u;
	} else if (minx == ans) {
		id = min(id, u);
	}

	return tsize[u];
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		idx = 1;
		cls(head);
		cls(edge);
		cls(tsize);
		cin >> n;
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			scanf("%d %d", &u, &v);
			add_edge(u, v);
			add_edge(v, u);
		}
		minx = inf;
		dfs(1, -1);
		cout << id << " " << minx << endl;

	}
	return 0;
}
