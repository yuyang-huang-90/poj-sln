//dp
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



const long long NMAX = 100005;
const long long EMAX = 1000005;
int m,n;
long long sum;
long long min_diff = 1000000;

struct Edge {
	int v, next;
};

Edge edge[EMAX * 2];
int head[NMAX];
long long dp[NMAX];
int visited[NMAX];
int idx;

void insert(int u, int v) {
	edge[idx].v = v;
	edge[v].next = head[u];
	head[u] = idx++;
}

long long my_abs(long long x) {
	return x > 0 ? x : -x;
}

void dfs(int u, int father) {
	if (visited[u] == 1) return;
	for (int i = head[u]; i != 0; i = edge[i].next) {
		int v = edge[i].v;
		if (v == father) continue;
		dfs(v,u);
		dp[u] += dp[v];
	}
	visited[u] = 1;
	min_diff = min(min_diff, (long long)my_abs((long long)(dp[u] - (sum - dp[u]))));
}

int main() {
	int u,v, t = 1;
	while (1) {
		cin>>n>>m;
		if (n == 0 && m == 0) {
			break;
		}
		cls(head);
		cls(visited);
		idx = 1;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &dp[i]);
			sum += dp[i];
		}
		for (int i = 0; i < m; ++i) {
			scanf("%d%d",&u,&v);
			insert(u,v);
			insert(v,u);
		}
		min_diff = 1000000;
		dfs(1, -1);
		printf("Case %d: %d\n",t++,min_diff);
	}
	return 0;
}
