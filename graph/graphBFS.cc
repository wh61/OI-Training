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
int q[maxn * 10];


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
		int head = 0, tail = -1;
		isVisited[root] = true;
		q[++tail] = root;
		while (head <= tail) {
			int v = q[head++];
			//do something here
			for (int i = l[v]; i != -1; i = E[i].x) {
				int ve = E[i].v;
				if (isVisited[ve]) continue;
				isVisited[ve] = true;
				q[++tail] = ve;
				//or do something here
			}
		}
	}
	return 0;
}
