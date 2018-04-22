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
const int SZ = 600;

int a[SZ];
int b[SZ];

void lcis(int *a, int n, int *b, int m) {
	int dp[SZ];
	int parent[SZ];
	cls(dp);
	cls(parent);
	for (int i = 0; i < n; ++i)
	{
		int cur = 0;
		int last = -1;
		for (int j = 0; j < m; ++j)
		{
			if (a[i] == b[j])
			{
				if (cur + 1 > dp[j]) {
					dp[j] = cur + 1;
					parent[j] = last;
				}
			}
			if (a[i] > b[j]) 
			{
				if (dp[j] > cur)
				{
					cur = dp[j];
					last = j;
				}
			}
		}
	}
	
	int rst = 0;
	int idx;
	for (int i = 0; i < m; ++i)
	{
		if (dp[i] > rst)
		{
			rst = dp[i];
			idx = i;
		}
	}
	cout << rst << endl;
	
	int tmp[SZ];
	for (int i = 0; idx != -1; ++i)
	{
		tmp[i] = b[idx];
		idx = parent[idx];
	}
	for (int i = rst - 1; i >= 0; --i)
	{
		cout << tmp[i] << " ";
	}
	cout << endl;
}

int main() {
	//freopen("./input.txt","r", stdin);
	int n, m;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> m;
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	lcis(a,n,b,m);
	return 0;
}
