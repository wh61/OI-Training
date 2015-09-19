#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int  maxn = 100005;
const int  maxm = 5000005;
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

int d[maxn]; //degree of nodes in the graph


int main() {
	freopen("in.txt", "r", stdin);
	int T, ca = 0;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		init();
		int x, y;
		for (int i = 1; i <= n; ++i) d[i] = 0;
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &x, &y);
			insert(x, y);
			d[y]++;
		}
		queue<int> q;
		for (int i = 1; i <= n; ++i) {
			if (d[i] == 0) q.push(i);
		}
		int cnt = 0;
		while (!q.empty()) {
			int v = q.front();
			cnt++;
			q.pop();
			for (int i = l[v]; i != -1; i = E[i].x) {
				int ve = E[i].v;
				if (--d[ve] == 0) q.push(ve);
				//--d[ve];
				//if (d[ve] == 0) q.push(ve);
			}
		}
		if (cnt == n) puts("Correct"); else puts("Wrong");
	}
	return 0;
}

