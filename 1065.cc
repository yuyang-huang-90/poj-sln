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


struct stick {
	int len;
	int w;
};

bool cmp(stick a, stick b) {
	if (a.len == b.len) {
		return a.w < b.w;
	}
	return a.len < b.len;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int c;
		cin >> c;
		vector<stick> data;
		for (int i = 0; i < c; ++i) {
			stick s;
			cin >> s.len >> s.w;
			data.push_back(s);
		}
		sort(data.begin(), data.end(), cmp);
		vector<bool> visited(c,false);
		int count = 0;
		for (int j = 0; j < c; ++j) {
			if (visited[j]) continue;
			visited[j] = true;
			int l = j;
			for (int k = l + 1; k < c; ++k) {
				if (data[l].w <= data[k].w && visited[k] == false) {
					l = k;
					visited[k] = true;
				}
			}
			++count;
		}
		cout << count << endl;
	}
	return 0;
}
