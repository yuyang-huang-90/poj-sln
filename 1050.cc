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


const int N = 200;
const int MAX = 0;
int temp[N];
int mat[N][N];

int maxsub(int *arr, int n) {
	int ans = arr[0];
	int maxend = arr[0];
	for (int i = 1; i < n; ++i) {
		if (maxend < 0) {
			maxend = arr[i];
		} else {
			maxend = arr[i] + maxend;
		}
		ans = max(ans, maxend);
	}
	return ans;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> mat[i][j];
		}
	}
	int ret = -MAX;
	for (int top = 0; top < n; ++top) {
		cls(temp);
		for (int bottom = top; bottom < n; ++bottom) {
			for (int j = 0; j < n; ++j) {
				temp[j] += mat[bottom][j];
			}
			ret = max(ret, maxsub(temp,n));
		}
	}
	cout << ret << endl;
	return 0;
}
