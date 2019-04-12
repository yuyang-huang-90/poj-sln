//binary search
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
#include<unordered_set>
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


int n, q;
const int INF = 0x3f3f3f3f;
const int SZ = 200009;
string s;
vector<pair<char,char>> ops(SZ);

bool okl(int ind) {
  char t = s[ind];
  for(int i = 0; i < q; ++i) {
    char c = ops[i].first;
    char op = ops[i].second;
    if(t == c){
      if(op == 'L'){
        ind--;
      }else{
        ind++;
      }
      if(ind == n) return false;
      if(ind == -1) return true;
      t = s[ind];
    }
  }
  return false;
}

int bs_left()
{
  int l = 0, r = n;
  while(l < r) {
    int m = (l + r) >> 1;
    if(!okl(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  return l;
}

bool okr(int ind) {
  char t = s[ind];
  for(int i = 0; i < q; ++i) {
    char c = ops[i].first;
    char op = ops[i].second;
    if(t == c){
      if(op == 'R'){
        ind++;
      }else{
        ind--;
      }
      if(ind == n) return true;
      if(ind == -1) return false;
      t = s[ind];
    }
  }
  return false;
}

int bs_right()
{
  int l = 0, r = n;
  while(l < r) {
    int m = (l + r) >> 1;
    if(okr(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  return l;
}

int main() {
  cin >> n >> q;
  cin >> s;
  for(int i = 0; i < q; ++i) {
    char ch, dir;
    cin >> ch >> dir;
    ops[i] = {ch, dir};
  }
  int left = bs_left();
  int right = bs_right();
  //cout << left << "," << right << endl;
  if(right > left) {
    cout  << right - left << endl;
  } else {
    cout << 0 << endl;
  }
	return 0;
}
