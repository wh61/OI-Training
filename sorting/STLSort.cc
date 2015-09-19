#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxn = 1000000;
int a[maxn];

int main() {
	int n = 100;
	for (int i = 0; i < n; ++i) a[i] = n - i;
	sort(a, a + n);
	for (int i = 0; i < n; ++i) printf("%d\n", a[i]);
	reverse(a, a + n);
	for (int i = 0; i < n; ++i) printf("%d\n", a[i]);
	return 0;
}
