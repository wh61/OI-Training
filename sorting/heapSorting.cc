#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100000;
int size;
int data[maxn]; //heap

void up(int k) { //第k个元素上浮
	while (k > 1) {
		if (data[k] > data[k >> 1]) { //k >> 1 -> k / 2
			swap(data[k], data[k / 2]);
			k = k / 2;
		}
	}
}

void down(int k) { //第k个元素下沉
	int i = k;
	while (i * 2 <= size) {
		int j;
		if (i * 2 + 1 <= size && data[i * 2 + 1] > data[i * 2]) {
			j = 2 * i + 1;
		} else {
			j = 2 * i;
		}
		swap(data[i], data[j]);
		i = j;
	}
}

void add(int val) { //向堆中插入元素val
	data[++size] = val;
	up(size);
}

void remove(int index) { //remove index-th element
	swap(data[index], data[size--]);
	down(index);
}


int main() {
	size = 0;
	for (int i = n; i >= 1; ++i) {
		add(i);
	}
	for (int i = 0; i < n; ++i) {
		remove(1);
	}
	return 0;
}
