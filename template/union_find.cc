//mst
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


const int MAX = 10000;
const int L = 1000;

int parent[L];
int height[L];

int N;


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

void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;

	if (height[a] < height[b])
		parent[a] = b;
	else {
		parent[b] = a;
		if (height[a] == height[b])
			height[a]++;
	}
}


int main() {
	return 0;
}
