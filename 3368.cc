//segment tree
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

#define root 1

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

const int INF = 0x3f3f3f3f;
const int MAX_N = 100020;

typedef pair<ll, ll> P;

int num[MAX_N], lleft[MAX_N], rright[MAX_N], tmax[MAX_N << 2];


#define lchild (idx << 1)
#define rchild (idx << 1 | 1)

int query(int L, int R, int l, int r, int idx) {
    if (r < L || l > R) {
        return -INF;
    }

    if (L <= l && r <= R) {
        return tmax[idx];
    }

    int m = (l + r) >> 1;
    int ret = -INF;
    ret = max(ret, query(L, R, l, m, lchild));
    ret = max(ret, query(L, R, m + 1, r, rchild));
    return ret;
}

void build(int idx, int l, int r) {
    if (l == r) {
        tmax[idx] = rright[l] - lleft[l] + 1;
        return;
    }

    int m = (l + r) >> 1;
    build(lchild, l, m);
    build(rchild, m + 1, r);
    tmax[idx] = max(tmax[lchild], tmax[rchild]);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    //---------------------------------------------
    // YOUR CODE
    int n, q;
    while (scanf("%d", &n) != EOF && n) {
        scanf("%d", &q);
        forn(i, n) {
            scanf("%d", &num[i]);
            if (!i || num[i] != num[i - 1]) lleft[i] = i;
            else lleft[i] = lleft[i - 1];
        }
        rforn(i, n) {
            if (i == (n - 1) || num[i] != num[i + 1]) rright[i] = i;
            else rright[i] = rright[i + 1];
        }
        build(root, 0, n - 1);
        forn(i, q) {
            int ql, qr;
            scanf("%d%d", &ql, &qr);
            ql--;
            qr--;
            if (num[ql] == num[qr]) {
                cout << qr - ql + 1 << endl;
            } else {
                int tmp = max(rright[ql] - ql + 1, qr - lleft[qr] + 1);
                if (rright[ql] + 1 > lleft[qr] - 1) {
                    cout << tmp << endl;
                } else {
                    tmp = max(tmp, query(rright[ql] + 1, lleft[qr] - 1, 0, n - 1, root));
                    cout << tmp << endl;
                }
            }
        }
    }
//---------------------------------------------
#ifndef ONLINE_JUDGE
    fclose(stdin);
    fclose(stdout);
#endif
    return 0;
}
