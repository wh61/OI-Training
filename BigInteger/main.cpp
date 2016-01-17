#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>



using namespace std;

const int maxn = 20022;
const int BASE = 10000;

struct BigInteger {
    int val[maxn];
    int bit;
    BigInteger(int num = 0) {
        bit = 0;
        while (num != 0) {
            val[++bit] = num % BASE;
            num = num / BASE;
        }
        if (bit == 0) {
            bit = 1;
            val[1] = 0;
        }
    }
    BigInteger(const string& str) {
        bit = 0;
        int sz = (int)str.size();
        for (int i = 0; i < sz; ++i) {
            val[++bit] = str[i] - '0';
        }
        bit = sz;
        reverse(val + 1, val + 1 + bit);
    }
    BigInteger(const BigInteger& rhs) {
        bit = rhs.bit;
        for (int i = 1; i <= bit + 1; ++i) {
            val[i] = rhs.val[i];
        }
    }
    BigInteger& operator=(const BigInteger& rhs) {
        bit = rhs.bit;
        for (int i = 1; i <= bit + 1; ++i) {
            val[i] = rhs.val[i];
        }
        return *this;
    }
    string toString() {
        string str;
        for (int i = bit; i > 0; --i) {
            str.push_back(val[i] + '0');
        }
        return str;
    }
    
};

BigInteger operator*(const BigInteger& lhs, const BigInteger& rhs) {
    BigInteger c;
    c.bit = lhs.bit + rhs.bit;
    for (int i = 0; i <= c.bit; ++i) {
        c.val[i] = 0;
    }
    for (int i = 1; i <= lhs.bit; ++i) {
        for (int j = 1; j <= rhs.bit; ++j) {
            c.val[i + j - 1] += lhs.val[i] * rhs.val[j];
            c.val[i + j] += c.val[i + j - 1] / BASE;
            c.val[i + j - 1] %= BASE;
        }
    }
    if (c.val[c.bit] == 0) --c.bit;
    return c;
}

bool operator<(const BigInteger& lhs, const BigInteger& rhs) {
    if (lhs.bit != rhs.bit) {
        return lhs.bit < rhs.bit;
    }
    for (int i = lhs.bit; i > 0; --i) {
        if (lhs.val[i] != rhs.val[i]) {
            return lhs.val[i] < rhs.val[i];
        }
    }
    return false;
}

char str[20005];


int main() {
    string str1, str2;
    scanf("%s", str);
    str1 = str;
    scanf("%s", str);
    str2 = str;

    BigInteger a(str1), b(str2);
    BigInteger c;
    c = a * b;
    //cout << c.toString() << endl;
    printf("%s\n", c.toString().c_str());
    return 0;
}