#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 14;

int a[maxn];
int n;


inline void print(int k) {
	for (int i = 1; i <= k; ++i) printf("%d ", a[i]);
}

void search(int k) {
	print(k);
	for (int i = a[k - 1] + 1; i <= n; ++i) {
		a[k] = i;
		search(k + 1);
	}
}

int main() {
	n = 10;
	a[0] = 0;
	search(1);
	return 0;
}
