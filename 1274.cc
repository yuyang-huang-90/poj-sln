//bigraph
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
#define initn1(x) memset(x,-1,sizeof(x))
#define initm(x) memset(x,0x3f,sizeof(x))
#define forn(i, n) for(int i = 0; i < (int) n; ++i)
#define for1(i, n) for(int i = 1; i <= (int) n; ++i)
#define fore(i, l, r) for(int i = (int) l; i <= (int) r; ++i)
#define rforn(i, n) for(int i = (int) n - 1; i>= 0; --i)
#define fi first
#define se second

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX_N = 300;
const int MAX_M = 300;

int match[MAX_N];
int e[MAX_N][MAX_N];
int checked[MAX_N];

typedef pair<ll, ll> P;

int n1, n2;

bool dfs(int u) {
    for1(v, n2) {
        if (e[u][v] && !checked[v]) {
            checked[v] = 1;
            int w = match[v];
            if (w < 0 || dfs(w)) {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungarin() {
    int ans = 0;
    initn1(match);
    for1(i, n1) {
        initz(checked);
        if (dfs(i)) ++ans;
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
//---------------------------------------------
// YOUR CODE
    while (scanf("%d%d", &n1, &n2) != EOF) {
        initz(e);
        for1(i, n1) {
            int t, j;
            scanf("%d", &t);
            while (t--) {
                scanf("%d", &j);
                e[i][j] = 1;
            }
        }
        printf("%d\n", hungarin());
    }

//---------------------------------------------
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
