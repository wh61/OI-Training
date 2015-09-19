#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
	int n = 3;
	for (int mask = 0; mask < 1 << n; ++mask) {
		for (int i = 0; i < n; ++i) {
			if ((mask >> i) & 1) {
				printf("%d", i + 1);
			}
		}
		puts("");
	}
	return 0;
}
