#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 555;

int n, m;

struct edge {
	int v, int w;
	edge(int v_, int w_) : v(v_), w(w_) {}
};

vector<edge> e[maxn];
//e[v][i]->edge
bool visited[maxn];

void dfs(int v) {
	visited[v] = true;
	int sz = e[v].size();
	for (int i = 0; i < sz; ++i) {
		int ve = e[v][i].v;
		if (visited[ve] == true) continue;
		dfs(ve);
	}
}

void bfs(int v) {
	queue<int> q;
	q.push(v);
	visited[v] = true;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		int sz = e[v].size();
		for (int i = 0; i < sz; ++i) {
			int ve = e[v][i].v, w = e[v][i].w;
			if (visited[ve]) continue;
			q.push(ve);
		}
	}
}

int main() {
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 1; i <= n; ++i) {
			e[i].clear();
			visited[i] = false;
		}
		for (int i = 1; i <= m; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			e[u].push_back(edge(v, 0));
			e[v].push_back(edge(u, 0));
		}
		int cnt = 0;
		for (int i = 1; i <= n; ++i) {
			if (!visited[i]) {
				cnt++;
		//		dfs(i);
				bfs(i);
			}
		}
	}
	return 0;
}
