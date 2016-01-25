#include <iostream>

using namespace std;

const int maxn = 5555;
int fa[maxn];

int getRoot(int v) {
    while (v != fa[v]) {
        v = getRoot(fa[v]);
    }
    return v;
}

void combine(int x, int y) {
    int root1 = getRoot(x), root2 = getRoot(y);
    if (root1 == root2) return;
    fa[root1] = root2;
}

bool check(int x, int y) {
    int root1 = getRoot(x), root2 = getRoot(y);
    return root1 == root2;
}

int main() {
    int n, m, p;
    while (scanf("%d%d%d", &n, &m, &p) != EOF) {
        for (int i = 0; i <= n; ++i) {
            fa[i] = i;
        }
        for (int i = 0; i < m; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            combine(x, y);
        }
        for (int i = 0; i < p; ++i) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (check(x, y)) printf("Yes\n"); else printf("No\n");
        }
    }
    return 0;
}