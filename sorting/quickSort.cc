#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;


const int maxn = 5000;

int a[maxn];

void sort(int left, int right) {
	if (left >= right) return;
	int mid = left + (right - left) / 2;
	int val = a[mid];
	int l = left, r = right;
	while (l < r) {
		while (l < right && a[l] < val) l++;
		while (left < r && a[r] > val) r--;
		if (l < r) {
			swap(a[l], a[r]);
			l++;
			r--;
		}
	}
	sort(left, r - 1);
	sort(l + 1, right);
}


int main() {
	//0~n
	int n = 10;
	for (int i = 0; i < n; ++i) a[i] = n - i;
	sort(0, n - 1);
	for (int i = 0; i < n; ++i) printf("%d\n", a[i]);
	return 0;
}
