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


const int MAX = 1002;
const int N = 100;

int dp_left[MAX];
int dp_right[MAX];

double a[MAX];

int main() {
	int n;
	while (scanf("%d", &n) != EOF) {
		cls(dp_left);
		cls(dp_right);
		for(int i = 1; i <= n; i++)
			scanf("%lf",&a[i]);
		for(int i = 1; i <= n; i++) {
			dp_left[i] = 1;
			for(int j = 1; j <i; j++) {
				if(a[i] > a[j] && dp_left[i] <dp_left[j] +1)
					dp_left[i] = dp_left[j]+1;
			}
		}
		for(int i = n; i >= 1; i--) {
			dp_right[i] = 1;
			for(int j = n; j > i; j--) {
				if(a[i] > a[j] && dp_right[i] <dp_right[j]+1)
					dp_right[i] = dp_right[j]+1;
			}
		}
		int ans = 0;
		for(int i = 1; i <n; i++) {
			for(int j = i+1; j <= n; j++) {
				if(dp_left[i] + dp_right[j] > ans)
					ans = dp_left[i] + dp_right[j];
			}
		}
		printf("%d\n",n-ans);
	}
	return 0;
}
