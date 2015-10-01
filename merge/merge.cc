


const int maxn = 50000;
int fa[maxn];
int n;

inline void init() {
	for (int i = 1; i <= n; ++i) fa[i] = i;
}

int getFa(int v) {
	while (v != fa[v]) {
		fa[v] = getFa(fa[v]);
		v = fa[v];
	}
	return v;
}

inline void join(int v1, int v2) {
	int fa1 = getFa(v1), fa2 = getFa(v2);
	if (fa1 == fa2) {
		return;
	} else {
		fa[fa1] = fa2;
	}
}

inline bool checkSameSet(int v1, int v2) {
	int fa1 = getFa(v1), fa2 = getFa(v2);
	return fa1 == fa2;
}




