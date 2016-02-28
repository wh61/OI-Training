#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int inf = 1000000000;

const int maxn = 222222;
const int maxm = 333333;
int dist[maxn];
bool inq[maxn];
int cnt[maxn];

struct edge {
    edge(int _u = 0, int _v = 0, int _w = 0) :u(_u), v(_v), w(_w), next(0) {}
    int u, v, w;
    int next;
}E[maxm * 3];

int e = 0, l[maxn];

void init() {
    e = 0;
    for (int i = 0; i < maxn; ++i) l[i] = -1;
}

void insert(int u, int v, int w) {
    E[e].u = u, E[e].v = v, E[e].w = w, E[e].next = l[u], l[u] = e++;
}



int main() {
    int n, m;
    
    scanf("%d%d", &n, &m);
    init();
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        insert(x, y, z);
        insert(y, x, z);
    }
    
    int st = n/2, ed = n;
    
    for (int i = 1; i <= n; ++i) {
        //cnt[i] = 0;
        dist[i] = inf;
        inq[i] = false;
    }
    dist[st] = 0;
    queue<int> q;
    q.push(st);
    inq[st] = true;
 //   cnt[st] = 1;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        inq[v] = false;
        //if (cnt[v] > n) break;
        for (int i = l[v]; i != -1; i = E[i].next) {
            int new_v = E[i].v;
            if (dist[v] + E[i].w < dist[new_v]) {
                dist[new_v] = dist[v] + E[i].w;
                if (!inq[new_v]) {
                    q.push(new_v);
                    //cnt[new_v]++;
                    inq[new_v] = true;
                }
            }
        }
    }
    
    int ans = dist[ed];
    
    printf("%d\n", ans);
    
    return 0;
}