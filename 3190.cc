//sweep line
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

const int BEGIN = 0;
const int END = 1;

struct period {
	int id;
	int type;
	int time;
};
period pt[100000];
int stall_for_cow[50000];

bool cmp (const period &a, const period &b) {
	if (a.time == b.time) {
		if (a.type == b.type) {
			return a.id < b.id;
		}
		return a.type < b.type;
	}
	return a.time < b.time;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int b, e;
		scanf("%d %d", &b, &e);
		pt[2*i].time = b;
		pt[2*i].id = i;
		pt[2*i].type = BEGIN;

		pt[2*i+1].time = e;
		pt[2*i+1].id = i;
		pt[2*i+1].type = END;
	}
	int sz = 2 * n;
	sort(pt, pt + sz, cmp);
	priority_queue<int,vector<int>,greater<int> > pq;
	int ans = 0;
	cls(stall_for_cow);
	for (int i =0; i < sz; ++i) {
		if (pt[i].type == END) {
			pq.push(stall_for_cow[pt[i].id]);
		} else {
			if (pq.empty()) {
				stall_for_cow[pt[i].id] = ++ans;
			} else {
				stall_for_cow[pt[i].id] = pq.top();
				pq.pop();
			}
		}
	}

	cout << ans << endl;
	for (int i = 0; i < n; ++i) {
		printf("%d\n", stall_for_cow[i]);
	}
	return 0;
}
