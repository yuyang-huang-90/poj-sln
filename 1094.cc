//toposort
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;
const int N = 30;
int in[N];
vector<int> edge[N];
char ans[N], q[N];

int n,m;

int topo_sort() {
	int d[N], ret = 1;
	memcpy(d,in,sizeof(d));
	int front = 0, rear = 0, p = 0;
	for (int i = 0; i < n; ++i) {
		if (d[i] == 0) q[rear++] = i;
	}
	while (front < rear) {
		if (rear - front > 1) ret = 0;
		int cur = q[front++];
		ans[p++] = 'A' + cur;
		for (int i = 0; i < edge[cur].size(); ++i) {
			int other = edge[cur][i];
			if (--d[other] == 0) q[rear++] = other;
		}
	}
	if (p < n) return -1;
	ans[p] = 0;
	return ret;
}


int main() {
	char a, b;
	while (scanf("%d %d", &n, &m)==2) {
		if (n == 0 && m == 0) break;
		memset(in, 0, sizeof(in));
		for (int i = 0; i < n; ++i) {
			edge[i].clear();
		}
		int flag = 0;
		for (int i = 0; i < m; ++i) {
			scanf(" %c<%c", &a, &b);
			if (flag) continue;
			a -= 'A';
			b -= 'A';
			edge[a].push_back(b);
			++in[b];
			flag = topo_sort();
			if(flag == 1)
				printf("Sorted sequence determined after %d relations: %s.\n", i + 1, ans);
			if(flag == -1)  
				printf("Inconsistency found after %d relations.\n", i + 1);
		}

		if (!flag) printf("Sorted sequence cannot be determined.\n");
	}

	return 0;
}
