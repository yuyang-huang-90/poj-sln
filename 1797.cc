//dijkstra
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
const int SZ = 1200;

struct Node {
	int num, capacity;
	Node(int num, int capacity) {
		this->num = num;
		this->capacity = capacity;
	}
};

int visited[SZ];
int d[SZ];
vector<Node> nxt[SZ];

class cmp {
	public:
		bool operator() (const Node &a, const Node &b) {
			return a.capacity < b.capacity;
		}
};

int main() {
	int t,n,m;
	cin >> t;
	for (int k = 0; k < t; ++k) {
		int ans = 0;
		cin >> n >> m;
		for (int i = 1; i <= n; ++i) {
			nxt[i].clear();
			visited[i] = 0;
			d[i] = 0;
		}
		for (int i = 0; i < m; ++i) {
			int a,b,cap;
			cin >> a >> b >> cap;
			Node e(b, cap);
			nxt[a].push_back(e);
			e.num = a;
			nxt[b].push_back(e);
		}
		priority_queue<Node, vector<Node>, cmp> pq;
		Node start(1,INF);
		pq.push(start);
		d[1] = INF;
		while (!pq.empty()) {
			Node u = pq.top();
			pq.pop();
			if (u.num == n) {
				ans = u.capacity;
				break;
			}
			if (visited[u.num] == 1) continue;
			visited[u.num] = 1;
			for (int i = 0; i < nxt[u.num].size(); ++i) {
				Node v = nxt[u.num][i];
				if (visited[v.num] == 1) continue;
				int cap = min(v.capacity, d[u.num]);
				if (d[v.num] < cap) {
					Node nn(v.num, cap);
					pq.push(nn);
				}
			}
		}

		cout<<"Scenario #" << k + 1 <<":" << endl << ans <<endl;
	}
	return 0;
}
