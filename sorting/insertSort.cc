#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;


const int maxn = 5000;

int a[maxn];

int main() {
	//0~n
	for (int i = 0; i < n; ++) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] > a[j]) {
				swap(a[i], a[j]);
			}
		}
	}
	return 0;
}
