//kruskal
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

struct Edge {
	int a;
	int b;
	int l;
};

const int L = 200;

int parent[L];
int height[L];

Edge edge[6000];

int g[L][L];

int N = 200;
int n;


void init() {
	for (int i = 0; i < N; ++i) {
		parent[i] = i;
		height[i] = 0;
	}
}

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = find(parent[a]);
}


bool same(int a, int b) {
	return find(a) == find(b);
}

bool unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;

	if (height[a] < height[b])
		parent[a] = b;
	else {
		parent[b] = a;
		if (height[a] == height[b])
			height[a]++;
	}
	return true;
}

bool cmp(const Edge &a, const Edge &b) {
	return a.l < b. l;
}

int main() {
	while (scanf("%d", &n) != EOF) {
		int idx = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cin >> g[i][j];
				if (i < j) {
					edge[idx].l = g[i][j];
					edge[idx].a = i;
					edge[idx].b = j;
					idx++;
				}
			}
		}
		sort(edge, edge + idx, cmp);
		init();
		int m;
		cin >> m;
		for (int i = 0; i < m; ++i) {
			int a, b;
			cin >> a >> b;
			unite(a-1, b-1);
		}
		int ans = 0;
		for (int i = 0; i < idx; ++i) {
			if (unite(edge[i].a, edge[i].b)) {
				ans += edge[i].l;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
