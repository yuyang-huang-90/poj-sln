//math
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


const double INF = 9999.9999;
const int SZ = 2003;
const double ep = 0.0001;

int x[SZ];
int y[SZ];
double slope[SZ];

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		for (int i = 0; i < n; ++i) {
			scanf("%d %d",&x[i],&y[i]);
		}
		if (n <= 2) {
			cout << n << endl;
			continue;
		}
		int ans = 2;
		for (int i = 0; i < n; ++i) {
			int idx = 0;
			for (int j = i+1; j < n; ++j) {
				if (x[i] == x[j]) {
					slope[idx++] = INF;
				} else {
					slope[idx++]=double(y[i]-y[j])/double(x[i]-x[j]);
				}
			}
			sort(slope, slope + idx);
			int cnt = 2;
			for (int j = 1; j < idx; ++j) {
				if (slope[j] - slope[j-1] < ep) {
					cnt++;
				} else {
					ans = max(ans,cnt);
					cnt = 2;
				}
			}
			ans = max(ans,cnt);
		}
		cout << ans << endl;
	}
	return 0;
}
