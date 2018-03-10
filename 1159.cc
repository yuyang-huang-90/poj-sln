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


int dp[2][5001];

int main(){
	int N;
	string s;
	cin >> N;
	cin >> s;
	cls(dp);
	int k = 0;
	for(int i = N - 2; i >= 0; i--){
		for(int j = i; j < N; j++){
			if(s[i] == s[j]) {
				dp[k][j] = dp[1 - k][j - 1];
			}
			else {
				dp[k][j] = 1 + min(dp[1 - k][j], dp[k][j - 1]);
			}
		}
		for (int j = 0; j < N; ++j) {
			dp[1-k][j] = 0;
		}
		k = 1 - k;
	}
	cout << dp[1 - k][N - 1] << endl;
	return 0;
}
