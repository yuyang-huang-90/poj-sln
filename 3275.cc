// floyd
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

const int N = 2000;

const int OUT = 0;
const int IN = 1;

struct Edge {
	int to, nxt;
};
Edge edge[2][1001000];
int idx[2];
int head[2][1100];
int visited[1005][1005];


void add(int a, int b, int d) {
	edge[d][idx[d]].to = b;
	edge[d][idx[d]].nxt = head[d][a];
	head[d][a] = idx[d]++;
}

int main() {
	int n, m, ans;
	while (scanf("%d %d", &n, &m) != EOF) {
		ans = 0;
		idx[IN] = idx[OUT] = 1;
		cls(head);
		cls(edge);
		cls(visited);
		for (int i = 0; i < m; ++i) {
			int a, b;
			scanf("%d %d", &a, &b);
			if (visited[a][b]) {
				continue;
			}
			visited[a][b] = 1;
			add(a, b, OUT);
			add(b, a, IN);
			ans++;
		}
		for (int k = 1; k <= n; ++k) {
			int a, b;
			for (int i = head[IN][k]; i != 0; i = edge[IN][i].nxt) {
				a = edge[IN][i].to;
				for (int j = head[OUT][k]; j != 0; j = edge[OUT][j].nxt) {
					b = edge[OUT][j].to;
					if (visited[a][b]) continue;
					visited[a][b] = 1;
					add(a, b, OUT);
					add(b, a, IN);
					ans++;
				}
			}
		}
		cout << n * (n - 1) / 2 - ans << endl;
	}
	return 0;
}
