/*
ID:sigefri2
LANG:C++11
TASK:ditch
*/

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

const int SZ = 250;
const long long MAX = 10000000;


long long c[SZ][SZ];
int flow;
int level[SZ];
int pre[SZ];
int gap[SZ];
int que[SZ];

int n,m;

void debug_info() {
	for (int i = 1; i <= m; ++i) {
		printf("level[%d] = %d\n", i, level[i]);
	}
	for (int i = 0; i < m; ++i) {
		printf("gap[%d] = %d\n", i, gap[i]);
	}
}

void bfs() {
	for (int i = 0; i <= m; ++i) {
		level[i] = m;
	}
	int s = 0, e = 1;
	que[s] = m;
	gap[0] = 1;
	level[m] = 0;
	while (s != e) {
		for (int i = 1; i <= m; ++i) {
			//if path exist and level uninitialized
			if (c[i][que[s]] != 0 && level[i] == m) {
				level[i] = level[que[s]] + 1;
				gap[level[i]]++;
				que[e] = i;
				e++;
			}
		}
		s++;
	}
}

void aug() {
	int cur = m, min_flow = MAX;
	while (cur != 1) {
		if (min_flow > c[pre[cur]][cur]) {
			min_flow = c[pre[cur]][cur];
		}
		cur = pre[cur];
	}
	cur = m;
	while (cur != 1) {
		c[pre[cur]][cur] -= min_flow;
		c[cur][pre[cur]] += min_flow;
		cur = pre[cur];
	}
	flow += min_flow;
}

void bfs_sap() {
	int cur = 1;
	int min_level_idx;
	int nxt;
	while (level[1] < m) {
		// augpath found, do augmentation and restart
		if (cur == m) {
			aug();
			cur = 1;
			continue;
		}
		// find path
		min_level_idx = 0;
		for (nxt = 1; nxt <= m; ++nxt) {
			if (level[nxt] == level[cur] - 1 && c[cur][nxt] != 0) {
				pre[nxt] = cur;
				cur = nxt;
				break;
			} else if (c[cur][nxt] != 0 && level[min_level_idx] > level[nxt]) {
				// find min level idx
				min_level_idx = nxt;
			}
		}
		if (nxt == m + 1) {
			// no path find, need to update gap and level
			gap[level[cur]]--;
			// update cur level need to find different path but if gap is breaked,
			// terminated the algorithm
			if (gap[level[cur]] == 0) break;
			level[cur] = level[min_level_idx] + 1; // if no path, the level will becomes MAX
			// if there is a path to min_level_idx, update the gap array;
			gap[level[cur]]++;
			// if it is not the start point, need to update the previous path
			if (cur != 1) cur = pre[cur];
		}
	}

}

bool found;
long long delta;
void dfs_sap(int v) {
	if (v == m) {
		found = true;
		flow += delta;
		return;
	}

	long long temp = delta;
	int min_level = m - 1, nxt;
	for (nxt = 1; nxt <= m; ++nxt) {
		if (c[v][nxt] > 0) {
			if (level[nxt] + 1 == level[v]) {
				// has next adjust flow
				delta = min(delta, c[v][nxt]);
				dfs_sap(nxt);
				if (level[1] >= m) return; //terminate condition
				if (found) break;
				delta = temp; // backtrack
			}
			min_level = min(min_level, level[nxt]);
		}
	}

	if (found) {
		c[v][nxt] -= delta;
		c[nxt][v] += delta;
	} else {
		// not found deal with update with gap and level
		gap[level[v]]--;
		if (gap[level[v]] == 0) level[1] = m;
		level[v] = min_level + 1;
		gap[level[v]]++;
	}

}


int main() {
	freopen("ditch.in", "r", stdin);
	freopen("ditch.out", "w", stdout);
	flow = 0;
	cls(c);
	cls(que);
	cls(gap);
	cls(pre);
	cls(level);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		int j,k,l;
		cin >>j >> k >> l;
		c[j][k] += l;
	}
	flow = 0;
	// bfs sap
	bfs();
	//bfs_sap();
	// dfs sap
	found = false;
	flow = 0;
	gap[0] = m;
	while (level[1] < m) {
		delta = MAX;
		found = false;
		dfs_sap(1);
	}
	cout << flow << endl;
	return 0;
}
