//deque
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

int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1 , 0, -1};

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const int MAX_N = 1000010;

int a[MAX_N], mi[MAX_N], ma[MAX_N];
deque<int> q, q2;

typedef pair<ll, ll> P;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);
#endif
//---------------------------------------------
// YOUR CODE
    int n, k;
    scanf("%d%d", &n, &k);
    forn(i, n) {
        scanf("%d", &a[i]);
    }

    forn(i, n) {
        if(!q.empty() && q.front() == i - k) {
            q.pop_front();
        }
        if(!q2.empty() && q2.front() == i - k) {
            q2.pop_front();
        }
        if (!q.empty() && q.front() == i - k) q.pop_front();
        if (!q2.empty() && q2.front() == i - k) q2.pop_front();


        while (!q.empty() && a[q.back()] >= a[i]) q.pop_back();
        q.push_back(i);

        while (!q2.empty() && a[q2.back()] <= a[i]) q2.pop_back();
        q2.push_back(i);

        if (i >= k - 1) {
            mi[i] = a[q.front()];
            ma[i] = a[q2.front()];
        }
    }
    for (int i = k - 1; i < n - 1; ++i) printf("%d ", mi[i]);
    printf("%d\n", mi[n - 1]);

    for (int i = k - 1; i < n - 1; ++i) printf("%d ", ma[i]);
    printf("%d\n", ma[n - 1]);


//---------------------------------------------
#ifndef ONLINE_JUDGE
	fclose(stdin);
	fclose(stdout);
#endif
	return 0;
}
