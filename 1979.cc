// dfs
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

char map[20][20];
int w, h, res;

void dfs(int x, int y) {
	res++;
	map[x][y] = 'M' ;
	if (x > 0 && map[x - 1][y] == '.')
		dfs(x - 1, y);
	if (y > 0 && map[x][y - 1] == '.')
		dfs(x, y - 1);
	if (x < h - 1 && map[x + 1][y] == '.')
		dfs(x + 1, y);
	if (y < w - 1 && map[x][y + 1] == '.')
		dfs(x, y + 1);
}

int main() {
	while (1) {
		scanf("%d %d\n", &w, &h);
		if (h == 0 && w == 0) break;
		int start_x = -1, start_y = -1;
		char enter;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				scanf("%c", &map[i][j]);
				if (map[i][j] == '@') {
					start_x = i;
					start_y = j;
				}
			}
			scanf("%c", &enter);
		}
		res = 0;
		dfs(start_x, start_y);
		printf("%d\n", res);
	}
	return 0;
}
