//uf
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
const int L = 1010;

int parent[L];
bool light[L];
int x[L], y[L];
vector<int> group[L];

int find(int a) {
	if (parent[a] == a) {
		return a;
	}
	return parent[a] = find(parent[a]);
}


void unite(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return;
    parent[a] = b;
}

int main() {
  int n, d;
  scanf("%d%d", &n, &d);
  char s[2];
  for(int i = 1; i <=n; ++i) {
	    scanf("%d%d", &x[i], &y[i]);
        parent[i] = i;
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; j++) {
      if (((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) <=
          d * d) {
        group[j].push_back(i);
        group[i].push_back(j);
      }
    }
  }
  while(~scanf("%s", s)) {
	  int a,b;
	  if(s[0] == 'O') {
		  scanf("%d", &a);
		  light[a] = true;
		  for(int i = 0; i < group[a].size(); ++i) {
			  if(light[group[a][i]]) {
				  b = find(group[a][i]);
				  parent[b] = a;
			  }
		  }
	  } else {
		  scanf("%d%d", &a, &b);
		  int pa = find(a);
		  int pb = find(b);
		  if(pa == pb) {
			  printf("SUCCESS\n");
		  } else {
			  printf("FAIL\n");
		  }
	  }
  }

  return 0;
}
