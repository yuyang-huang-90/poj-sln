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

using namespace std;
typedef long long ll;
#define cls(x) memset(x,0,sizeof(x))


const int INF = 0x3f3f3f3f;
const int SZ = 100;

struct stat {
	int dist;
	int vol;
};

bool cmp(const stat &a, const stat &b) {
	return a.dist > b.dist;
}

int main() {
	int n;
	cin >> n;
	vector<stat> dat(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d %d", &dat[i].dist, &dat[i].vol);
	}
	sort(dat.begin(), dat.end(), cmp);
	priority_queue<int> pq;
	int l, p;
	scanf("%d %d", &l, &p);
	int rest = l - p;
	vector<stat>::iterator it = dat.begin();
	vector<stat>::iterator it_end = dat.end();
	int ans = 0;
	while (rest > 0) {
		while (it != it_end && it->dist >= rest) {
			pq.push(it->vol);
			++it;
		}
		if (pq.empty()) {
			ans = -1;
			break;
		} else {
			rest -= pq.top();
			++ans;
			pq.pop();
		}
	}
	cout << ans << endl;
	return 0;
}
