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
typedef long long ll;
#define cls(x) memset(x,0,sizeof(x))

struct Item {
	ll v,w;
};


const int MAX = 100000;
const int N = 100;
ll dp[MAX + 1];

ll solve(vector<Item> &items, int W) {
	cls(dp);
	for (int i = 0; i < items.size(); ++i) {
		for (int j = W; j >= items[i].w; --j) {
			dp[j] = max(dp[j], dp[j-items[i].w] + items[i].v);
		}
	}
	return dp[W];
};

int main() {
	ll W, N;
	while (scanf("%lld %lld", &W, &N) != EOF) {
		vector<Item> items;
		for (int i = 0; i < N; i++) {
			ll val, num;
			scanf("%lld %lld", &num, &val);
			for (ll k = 1; k <= num; k *= 2) {
				items.push_back((Item) {k * val, k * val});
				num -= k;
			}
			if (num > 0) {
				items.push_back((Item) {num * val, num * val});
			}
		}
		printf("%lld\n", solve(items,W));
	}
	return 0;
}
