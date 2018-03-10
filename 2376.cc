//greedy
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
#include<utility>

using namespace std;
typedef long long ll;
#define cls(x) memset(x,0,sizeof(x))


const int INF = 0x3f3f3f3f;
const int SZ = 25005;

pair<int,int> v[SZ];


int main() {
	int n, t;
	cin >> n >> t;
	int from = 1, to = 0, cnt = 1;
	for (int i = 0; i < n; ++i) {
		cin >> v[i].first >> v[i].second;
	}
	sort(v, v+n);
	for (int i = 0; i < n; ++i) {
		if (v[i].first > from) {
			++cnt;
			from = to + 1;
		}
		if (v[i].first <= from) {
			to = max(to, v[i].second);
			if (to >= t) break;
		} else break;
	}
	printf("%d\n", to < t ?  -1 : cnt);
	return 0;
}
