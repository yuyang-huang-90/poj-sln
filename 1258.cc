//prim
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <string>
#include <cassert>

const int N = 101;
int graph[N][N];
int visited[N];
long long d[N];
int n;
const int MAX=0x3f3f3f3f;


void print_g() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			printf("%d ", graph[i][j]);
		}
		printf("\n");
	}
}

int prim() {
	memset(visited,0,sizeof(visited));
	memset(d,MAX, sizeof(d));
	d[0] = 0;
	int ret = 0;
	for (int k = 0; k < n; ++k) {
		int min_idx = -1;
		int min_val = MAX;
		//select min
		for (int i = 0; i < n; ++i) {
			if (!visited[i] && d[i] < min_val) {
				min_idx = i;
				min_val = d[i];
			}
		}
		assert(min_idx >= 0 && min_idx < n);
		visited[min_idx] = 1;
		ret += d[min_idx];
		// travel adj
		for (int j = 0; j < n; ++j) {
			if (!visited[j] && graph[min_idx][j] < d[j]) {
				d[j] = graph[min_idx][j];
			}
		}
	}

	return ret;
}

int main() {
	memset(graph,0,sizeof(graph));
	while (scanf("%d", &n) != EOF) {
		if (n == 0) break;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				scanf("%d", &graph[i][j]);
			}
		}
		//print_g();
		printf("%d\n",prim());
	}
	return 0;
}
