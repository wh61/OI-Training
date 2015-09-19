#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 14;

int a[maxn];
bool used[maxn];
int n;

inline void print() {
	for (int i = 0; i < n; ++i) {
		printf("%d ", a + i);
	}
}

void dfs(int k) {
	if (k >= n) {
		print();
		return;
	}
	for (int i = 1; i <= n; ++i) {
		if (used[i]) continue;
		used[i] = true;
		a[k] = i;
		dfs(k + 1);
		used[i] = false;
	}
}

int main() {
	memset(used, false, sizeof(used));
	n = 5;
	dfs(0);
	return 0;
}
