#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int  maxn = 10005;
const int  maxm = 300005;
const int inf = 0x3fffffff;

struct Edge{ 
	int u,v;
	int x; //point to next;
}E[maxm];

int e,l[maxn];
inline void init() { e=0; memset(l,-1,sizeof(l)); }
inline void insert(int u, int v){ //单向边
		E[e].u=u; E[e].v=v; E[e].x=l[u]; l[u]=e++;
}

bool isVisited[maxn];
int cnt = 0;

void dfs(int v) {
	if (isVisited[v]) return;
	cnt++;
	for (int i = l[v]; i != -1; i = E[i].x) {
		dfs(E[i].v);
	}
}

int main() {
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		init();
		int x, y, z;
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &x, &y);
			insert(x, y);
			insert(y, x);
		}
		memset(isVisited, 0, sizeof(isVisited));
		// for (int i = 1; i <= n; ++i) isVisited[i] = false;
		int root = 1;
		cnt = 0;
		isVisited[root] = true;
		dfs(root);
		if (cnt == n) {
			puts("all the nodeds are connected"); 
		} else {
			puts("not all the nodes are connected"); 
		}
	}
	return 0;
}


