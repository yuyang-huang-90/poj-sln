//greedy
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<deque>
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
#include<limits>
#include<utility>

//#define c11
#ifdef c11
#include<unordered_set>
#include<unordered_map>
#endif

using namespace std;
typedef long long ll;
#define ull unsigned long long
#define PI acos(-1.0)
#define eps 1e-12
#define initz(x) memset(x,0,sizeof(x))
#define initm(x) memset(x,0x3f,sizeof(x))
#define forn(i, n) for(int i = 0; i < (int) n; ++i)
#define for1(i, n) for(int i = 1; i <= (int) n; ++i)
#define fore(i, l, r) for(int i = (int) l; i <= (int) r; ++i)
#define rforn(i, n) for(int i = (int) n - 1; i>= 0; --i)
#define fi first
#define se second

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1 , 0, -1};

const int INF = 0x3f3f3f3f;
const int MAX_N = 50000 + 16;
const int MAX_M = 5000;

struct Cow
{
	int weight, strength;
	bool operator < (const Cow& other) const
	{
		return other.strength + other.weight < strength + weight;
	}
};

Cow cow[MAX_N];

typedef pair<int, int> P;

int main() {
  int N;
  cin >> N;
  int total = 0;
  forn(i, N) {
    cin >> cow[i].weight >> cow[i].strength;
    total += cow[i].weight;
  }
  sort(cow, cow + N);
  int risk = -INF;
  forn(i, N) {
    total -= cow[i].weight;
    risk = max(risk, total - cow[i].strength);
  }
  cout << risk << endl;
	return 0;
}
