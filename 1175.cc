//implemetation
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
#include<cmath>
#include<iostream>
#include<utility>

using namespace std;
typedef long long ll;
#define cls(x) memset(x,0,sizeof(x))

struct point {
	int x;
	int y;
};
const int N = 105;
const int mod=1999997;


int w;
int h;
int visited[N][N];
char mat[N][N];
char output[N][N];
point pt[N];
int pc = 0;

char flag_char = 'a';
map<pair<long long,long long>,char> flag_map;


int dx[]={-1,-1,-1,0,1,1,1,0};
int dy[]={-1,0,1,1,1,0,-1,-1};

void print_output() {
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cout << output[i][j];
		}
		cout << endl;
	}
}

void append(int x, int y) {
	pt[pc].x = x;
	pt[pc].y = y;
	pc++;
}

bool valid(int x, int y) {
	return x >= 0 && x < h && y >= 0 && y < w && mat[x][y] == '1';
}

void dfs(int x, int y) {
	if (visited[x][y] == 1) return;
	visited[x][y] = 1;
	append(x,y);
	for (int t = 0; t < 8; ++t) {
		int nx = x + dx[t];
		int ny = y + dy[t];
		if (valid(nx,ny) && visited[nx][ny] == 0) {
			dfs(nx, ny);
		}
	}
}

char getcode() {
	int sumx = 0, sumy = 0;
	for (int i = 0; i < pc; ++i) {
		sumx += pt[i].x;
		sumy += pt[i].y;
	}
	double xx= 1.0 * sumx / pc, yy = 1.0 * sumy / pc;
	double det = 0.0;
	for (int i = 0; i < pc; ++i) {
		det+=1.0*(pt[i].x-xx)*(pt[i].x-xx)*(pt[i].x-xx)*(pt[i].x-xx)+1.0*(pt[i].y-yy)*(pt[i].y-yy)*(pt[i].y-yy)*(pt[i].y-yy);
	}
	long long key1 = pc;
	long long key2 = (long long) (det * 10);
	key2 = key2 % mod;
	pair<long long,long long> key = make_pair(key1,key2);
	if (flag_map.count(key) == 0) {
		flag_map[key] = flag_char++;
	}
	return flag_map[key];
}

void mark() {
	for (int t = 0; t < pc; ++t) {
		char cur = getcode();
		output[pt[t].x][pt[t].y] = cur;
	}
}

void solve() {
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if(visited[i][j] == 0 && mat[i][j] == '1') {
				pc = 0;
				dfs(i,j);
				mark();
			}
		}
	}
}


int main() {
	cls(visited);
	cin >> w >> h;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> mat[i][j];
			output[i][j] = '0';
		}
	}
	solve();
	print_output();
	return 0;
}

