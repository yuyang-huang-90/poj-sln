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
#include<string>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>

using namespace std;
typedef long long ll;
#define cls(x) memset(x,0,sizeof(x))

bool check(string &str, int left, int right) {
	if (left < 1) return false;
	if (left == right) {
		return str[left] > '0' && str[left] <= '9';
	}
	if (left + 1 == right) {
		int num = stol(str.substr(left,2));
		return num >= 10 && num <= 26;
	}
	return false;
}

int main() {
	string str;
	while (1) {
		cin >> str;
		if (str == "0") {
			break;
		}
		str = "-" + str;
		int p2 = 1, p1 = 1, cur = 0;
		for (int i = 1; i < str.length(); ++i) {
			if (check(str,i,i)) {
				cur += p1;
			}
			if (check(str,i-1,i)) {
				cur += p2;
			}
			p2 = p1;
			p1 = cur;
			cur = 0;
		}
		cout << p1 << endl;
	}
	return 0;
}
