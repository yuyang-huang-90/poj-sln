//search
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

using namespace std;
typedef long long ll;
#define cls(x) memset(x,0,sizeof(x))


const int MAX = 10000;
const int N = 100;

const int dir[8][2] = {
	{-2,-1}, {-2,1}, {-1,-2},{-1,2},
	{1,-2},{1,2},{2,-1},{2,1}};

struct Path{
	int x, y;
};
Path path[32*32+1];
bool mm[32][32];
int p, q;

bool dfs(int x, int y, int order)
{
	mm[x][y] = true;
	path[order].x = x;
	path[order].y = y;
	if (order == p*q)
		return true;

	int xt, yt;
	for (int i = 0; i < 8; i++){
		xt = x + dir[i][0];
		yt = y + dir[i][1];
		if (1<=xt&&xt<=q && 1<=yt&&yt<=p && !mm[xt][yt]){
			if (dfs(xt, yt, order+1))
				return true;
		}
	}
	mm[x][y] = false;
	return false;
}

int main()
{
	int t, cnt = 0;
	scanf("%d", &t);
	while (t--){
		scanf("%d %d", &p, &q);

		memset(mm, 0, sizeof(mm));

		printf("Scenario #%d:n", ++cnt);
		if (!dfs(1, 1, 1)){
			printf("impossiblen");
		}
		else{
			for (int i = 1; i <= p*q; i++)
				printf("%c%d", (char)(path[i].x+'A'-1), path[i].y);
			printf("\n");
		}
		if (t)
			printf("\n");
	}
	return 0;
}
