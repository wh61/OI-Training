#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxm = 120;
const int maxn = 1111;
int n, m;
int dp[maxn][maxm];
int c[maxn], e[maxn];
bool visited[maxn];

struct edge {
    int v;
    int next;
    edge(int _v = 0, int _next = 0) : v(_v), next(_next) {}
};

edge E[maxn * 2];
int l[maxn]; //-1 -> NULL
int ee;

void init() {
    ee = 0;
    memset(l, -1, sizeof(l));
}

void insert(int u, int v) {
    E[ee].v = v; E[ee].next = l[u]; l[u] = ee++;
}


void dfs(int v) {
    visited[v] = true;
    //cnt[v] = 1;
    
    //
    for (int i = l[v]; i != -1; i = E[i].next) {
        int ve = E[i].v;
        if (visited[ve]) continue;
        //dfs(ve);
        //cnt[v] += cnt[ve];
        dfs(ve);
        for (int V = m; V >= 0; V--) {
            for (int V0 = 0; V0 <= V; ++V0) {
                dp[v][V] = max(dp[v][V], dp[v][V - V0] + dp[ve][V0]);
            }
        }
    }
    //
    for (int i = c[v]; i <= m; ++i) {
        dp[v][i] = max(dp[v][i], e[v]);
    }
    //
}



int main() {
    scanf("%d%d", &n, &m);
    init();
    for (int i = 2; i <= n; ++i) {
        int fa;
        scanf("%d", &fa);
        insert(fa, i);
        insert(i, fa);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &c[i]);
    }
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &e[i]);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) visited[i] = false;
    dfs(1);
    printf("%d\n", dp[1][m]);
    return 0;
}