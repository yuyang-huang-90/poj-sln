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

using namespace std;
#define cls(x) memset(x,0,sizeof(x))


const int MAX = 10000;
const int N = 100;

const int mid = 7500;

int dp[24][mid * 2 + 1];
int C[24], G[24], c, g;

int main() {
	scanf("%d %d", &c, &g);
	for (int i = 1; i <= c; i++)
		scanf("%d", &C[i]);
	for (int i = 1; i <= g; i++)
		scanf("%d", &G[i]);
	memset(dp, 0, sizeof(dp));
	dp[0][mid] = 1;
	for (int i = 1; i <= g; i++)
		for (int j = 1; j <= c; j++)
			for (int k = -7500; k <= 7500; k++)
				dp[i][k+C[j]*G[i]+7500] += dp[i-1][k+7500];

	printf("%d\n", dp[g][mid]);

	return 0;
}
