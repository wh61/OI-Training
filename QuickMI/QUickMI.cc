#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MOD = 1000000007;

typedef long long LL;

int getMI(int k, int n) {
    if (n == 0) return 1;
    if (n == 1) return k % MOD;
    int temp = getMI(k, n / 2);
    LL temp_val = LL(temp) * temp % MOD;
    if (n % 2 == 0) {
        return (int)temp_val;
    } else {
        return (temp_val * k) % MOD;
    }
}


int main() {
    return 0;
}