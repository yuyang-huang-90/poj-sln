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


const int INF = 0x3f3f3f3f;
const int SZ = 105;
int m,n;

int mat[SZ][SZ];
int dp[SZ][SZ];

int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};

bool valid(int x, int y) {
	return x >= 0 && x < m && y >= 0 && y < n;
}

int main() {
	cin >> m >> n;
	cls(dp);
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mat[i][j];
		}
	}
	int ans = 0;
	bool updated = true;
	while (updated) {
		updated = false;
		for (int x = 0; x < m; ++x) {
			for (int y = 0; y < n; ++y) {
				for (int k = 0; k < 4; k++) {
					int nx = x + dx[k];
					int ny = y + dy[k];
					if (valid(nx,ny)) {
						if (mat[x][y] > mat[nx][ny]) {
							if (dp[nx][ny] + 1 > dp[x][y]) {
								dp[x][y] = dp[nx][ny] + 1;
								updated = true;
								ans = max(ans, dp[x][y]);
							}
						}
					}
				}
			}
		}
	}
	cout << ans + 1 << endl;

	return 0;
}
