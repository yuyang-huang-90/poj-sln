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

int main() {
	int T;
	cin >> T;
	long long int  N;
	for (int i = 0; i < T; i++)
	{
		cin >> N;
		int ret = 0;
		while (N)
		{
			ret = ret + N / 5;
			N = N / 5;
		}
		cout << ret << endl;
	}
	return 0;
}
