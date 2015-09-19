#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 1005;
const int maxm = 1000055;
const int inf = 0x3fffffff;

struct Edge{ 
	int u,v,w;
	int x; //point to next;
}E[maxm];

int e,l[maxn];
inline void init() { e=0; memset(l,-1,sizeof(l)); }
inline void insert(int u, int v, int w) { //单向边
		E[e].u=u; E[e].v=v; E[e].w=w; E[e].x=l[u]; l[u]=e++;
}

bool isOK[maxn];
int dist[maxn];


int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		init();
		int x, y, z;
		for (int i = 0; i < m; ++i) {
			scanf("%d%d%d", &x, &y, &z);
			insert(x, y, z);
			insert(y, x, z);
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
			for (int i = l[v]; i != -1; i = E[i].x) {
				int ve = E[i].v;
				int w = E[i].w;
				dist[ve] = min(dist[v] + w, dist[ve]);
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
