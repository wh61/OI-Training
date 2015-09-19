#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1005;
const int inf = 0x3fffffff;


bool isOK[maxn];
int dist[maxn];

int w[maxn][maxn];



int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		//init();
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j <= n; ++j) {
				w[i][j] = inf;
			}
		}
		for (int i = 1; i <= n; ++i) w[i][i] = 0;
		int x, y, z;
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &x, &y, &z);
			w[x][y] = z;
			w[y][x] = z;
		}
		memset(isOK, false, sizeof(isOK));
		for (int i = 1; i <= n; ++i) {
			dist[i] = inf;
		}
		int st = 1;
		dist[st] = 0;
		isOK[st] = true;
		int v = st;
		for (int k = 1; k < n; ++k) {
			for (int ve = 1; ve <= n; ++ve) {
				dist[ve] = min(dist[v] + w[v][ve], dist[ve]);
			}
			int mindist = inf, cur = 0;
			for (int i = 1; i <= n; ++i) {
				if (!isOK[i]) {
					if (dist[i] < mindist) {
						mindist = dist[i];
						cur = i;
					}
				}
			}
			v = cur;
			isOK[cur] = true;
		}
		for (int i = 1; i <= n; ++i) {
			printf("%d", dist[i]);
			if (i < n) printf(" ");
		}
	}
	return 0;
}
