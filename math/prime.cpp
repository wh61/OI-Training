#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <vector>

const int maxn = 5000050;
bool ok[maxn];

using namespace std;


int main() {
    
    int number;
    scanf("%d", &number);
    int sqrt_number = sqrt(number) + 2;
    bool flag = true;
    for (int i = 2; i < sqrt_number; ++i) {
        if (sqrt_number % i == 0) {
            flag = false;
            break;
        }
    }
    
    for (int i = 2; i < maxn; ++i) {
        ok[i] = true;
    }
    
    vector<int> p_vec;
    for (int i = 2; i < maxn; ++i) {
        if (ok[i]) {
            p_vec.push_back(i);
            for (int j = 2 * i; j < maxn; j += i) {
                ok[j] = false;
            }
        }
    }
    
    return 0;
}