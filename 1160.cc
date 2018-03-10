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


const int MAX = 0x3fffffff;
const int N = 400;

int dp[N][N];
int dist[N][N];
int x[N];

int calc_dist(int i, int j) {
	int ret = 0;
	while (i < j) {
		ret += x[j] - x[i];
		i++;
		j--;
	}
	return ret;
}

int main() {
	cls(dp);
	int vil, post;
	while (scanf("%d %d", &vil, &post) != EOF) {
		x[0] = 0;
		for (int i = 1; i <= vil; ++i) {
			cin >> x[i];
		}
		for (int i = 1; i <= vil; ++i) {
			for (int j = i; j <= vil; ++j) {
				dist[i][j] = calc_dist(i,j);
			}
		}
		for (int i = 0; i <= post; ++i) {
			for (int j = 0; j <= vil; ++j) {
				dp[i][j] = MAX;
			}
		}
		for (int i = 0; i <= post; ++i) {
			dp[i][0] = 0;
		}
		for (int j = 1; j <= vil; ++j) {
			dp[1][j] = dist[1][j];
		}
		for (int i = 1; i <= post; ++i) {
			for (int j = i; j<= vil; ++j) {
				for (int k = 1; k < j; ++k) {
					dp[i][j] = min(dp[i][j], dp[i-1][k] + dist[k+1][j]);
				}
			}
		}
		cout << dp[post][vil] << endl;
	}
	return 0;
}
