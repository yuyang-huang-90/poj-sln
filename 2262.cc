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


const int MAX = 10000;
const int N = 100;

bool sieve[1000001];
int main() {
	int n;
	memset(sieve, true, sizeof(sieve));
	sieve[0] = sieve[1] = false;
	for(int i = 2; i <= 1000000; i++) {
		if(sieve[i])
			for(int j = 2 * i; j <= 1000000; j += i)
				sieve[j] = false;
	}
	while(scanf("%d", &n) != EOF && n != 0){
		for(int i = 3; i <= n - i; i += 2)
			if(sieve[i] && sieve[n - i]){
				cout << n << " = " << i << " + " << n - i << endl;
				break;
			}
	}
	return 0;
}
