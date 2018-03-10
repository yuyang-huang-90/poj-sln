#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<list>
#include<algorithm>

using namespace std;

#define cls(c) memset(c, 0, sizeof(c))


const int INF = 0x3f3f3f3f;

const int MAXN = 520;

int visited[MAXN];
int match[MAXN];
int mat[MAXN][MAXN];

int n, k;

bool dfs(int v) {
	for (int j = 1; j <= n; ++j) {
		if (mat[v][j] == 1 && visited[j] == 0) {
			visited[j] = 1;
			if (match[j] == 0 || dfs(match[j])) {
				match[j] = v;
				return true;
			}
		}
	}

	return false;
}

int main() {
	while (scanf("%d %d", &n, &k) != EOF) {
		cls(match);
		cls(mat);
		int x,y;
		for (int i = 0 ; i < k; ++i) {
			scanf("%d %d", &x, &y);
			mat[x][y] = 1;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			cls(visited);
			if (dfs(i)) ans++;
		}
		cout << ans << endl;

	}

	return 0;
}
