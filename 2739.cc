// two pointer
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <vector>

//#define c11
#ifdef c11
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;
typedef long long ll;
#define ull unsigned long long
#define PI acos(-1.0)
#define eps 1e-12
#define initz(x) memset(x, 0, sizeof(x))
#define initm(x) memset(x, 0x3f, sizeof(x))
#define forn(i, n) for (int i = 0; i < (int)n; ++i)
#define for1(i, n) for (int i = 1; i <= (int)n; ++i)
#define fore(i, l, r) for (int i = (int)l; i <= (int)r; ++i)
#define rforn(i, n) for (int i = (int)n - 1; i >= 0; --i)
#define fi first
#define se second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const int INF = 0x3f3f3f3f;
const int MAX_N = 30;
const int MAX_M = 11000;

typedef pair<int, int> P;

vector<bool> is_prime;
vector<int> primes;

void init_primes() {
  is_prime = vector<bool>(MAX_M, true);
  is_prime[0] = is_prime[1] = false;
  for (int i = 2; i <= MAX_M; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i * 2; j <= MAX_M; j += i) {
        is_prime[j] = false;
      }
    }
  }
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
  init_primes();
  int n;
  int sz = primes.size();
  while (cin >> n && n) {
    int l = 0, r = 0, sum = 0, result = 0;
    for (;;) {
      while (sum < n && r < sz) {
        sum += primes[r++];
      }
      if (sum < n) {
        break;
      } else if (sum == n) {
        ++result;
      }
      sum -= primes[l++];
    }
    cout << result << endl;
  }
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
#endif
  return 0;
}
