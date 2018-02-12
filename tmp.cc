// dp
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
  
typedef long long int64;  
const int INF = 0x3f3f3f3f;  
  
const int MAXN = 20010;  
int tot[MAXN];  
int f[MAXN], minx, id;  
  
namespace Adj {  
    int size, head[MAXN];  
    struct Node{  
        int v, next;   
    }E[MAXN*2];  
    inline void initAdj() {  
        size = 0;  
        memset(head, -1, sizeof(head));  
    }  
    inline void addEdge(int u, int v) {  
        E[size].v = v;  
        E[size].next = head[u];  
        head[u] = size++;  
    }  
}  
using namespace Adj;  
  
int n;  
  
int dfs(int u, int fa) {  
  
    tot[u] = 1;  
    // count  
    for (int e = head[u]; e != -1; e = E[e].next) {  
        int v = E[e].v;  
        if (v == fa) continue;  
        tot[u] += dfs(v, u);  
    }  
    // 保存答案  
    int& ans = f[u] = n - tot[u];  
    for (int e = head[u]; e != -1; e = E[e].next) {  
        int v = E[e].v;  
        if (v == fa) continue;  
        ans = max(ans, tot[v]);  
    }  
    if (ans < minx) {  
        minx = ans;    
        id  = u;  
    } else if(ans == minx) {  
        id = min(id, u);   
    }  
    return tot[u];  
}  
  
int main(){  
    int nCase;  
    scanf("%d", &nCase);  
  
    while (nCase--) {  
          
        scanf("%d", &n);  
  
        initAdj();  
        for (int i = 0; i < n - 1; ++i) {  
            int u, v;  
            scanf("%d%d", &u, &v);   
            addEdge(u, v);  
            addEdge(v, u);  
        }  
        minx = INF;  
        dfs(1, -1);  
        printf("%d %d\n", id, minx);  
    }  
  
    return 0;  
}  
