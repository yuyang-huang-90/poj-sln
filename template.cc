// TYPE
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
const int SZ = 10;

struct Edge {
	int to, nxt;
};

Edge edge[SZ];
int head[SZ];
int idx = 0;

void add_edge(int u, int v) {
	edge[idx].to = v;
	edge[idx].nxt = head[u];
	head[u] = idx++;
}


int main() {
	return 0;
}
