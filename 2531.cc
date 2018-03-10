//TYPE
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


const int INF = 0x3f3f3f3f;
const int SZ = 100;

const int A = 0;
const int B = 1;
int n, ans;
int c[32][32];
int mark[32];

void dfs(int depth, int sum) {
	if (depth == n) {
		if (sum > ans) {
			ans = sum;
		}
		return;
	}

	int tmp = 0;
	mark[depth] = A;
	for (int i = 0; i < depth; ++i) {
		if (mark[i] == B) {
			tmp += c[depth][i];
		}
	}
	dfs(depth + 1, tmp + sum);

	tmp = 0;
	mark[depth] = B;
	for (int i = 0; i < depth; ++i) {
		if (mark[i] == A) {
			tmp += c[depth][i];
		}
	}
	dfs(depth + 1, tmp + sum);
}

int main() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> c[i][j];
		}
	}
	cls(mark);
	mark[0] = A;
	ans = 0;
	dfs(1, 0);
	cout << ans << endl;
	return 0;
}
