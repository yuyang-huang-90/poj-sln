#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <set>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <utility>
#include <vector>

using namespace std;
#define cls(c) memset(c,0,sizeof(c))
const double eps = 1E-8;
const int dx[4]={1,0,0,-1};
const int dy[4]={0,-1,1,0};
const int inf = 0x3f3f3f3f;

const int N = 2000;

void print_nxt(vector<int> &nxt) {
	for (int i = 0; i < nxt.size(); ++i) {
		cout << i << " " << nxt[i] << endl;
	}
}

void calc_nxt(string &target, vector<int> &nxt) {
	int j = -1;
	nxt[0] = j;
	for (int i = 1; i < target.size(); ++i) {
		while (j != -1 && target[j+1] != target[i]) j = nxt[j];
		if (target[i] == target[j+1]) j++;
		nxt[i] = j;
	}
}

void kmp_match(string a, string b, vector<int> &nxt) {
	int j = -1;
	for (int i = 0; i < a.size(); ++i) {
		while (j >= 0 && a[i] != b[j+1]) j = nxt[j];
		if (a[i] == b[j+1]) j++;
		if (j == b.size() - 1) {
			cout << "match idx: " << i - b.size() + 1 << endl;
			j = nxt[j];
		}
	}
}

int main() {
	string b = "ababa";
	vector<int> nxt(b.size(), -1);
	calc_nxt(b,nxt);
	print_nxt(nxt);
	string a = "ccababacababa";
	kmp_match(a,b,nxt);
	return 0;
}
