#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>



using namespace std;

const int maxm = 88;
const int maxn = 555;
const int BASE = 10;

struct BigInteger {
    int val[maxn];
    int bit;
    BigInteger(long long num = 0) {
        memset(val, 0, sizeof(val));
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
        memset(val, 0, sizeof(val));
        bit = 0;
        int sz = (int)str.size();
        for (int i = 0; i < sz; ++i) {
            val[++bit] = str[i] - '0';
        }
        bit = sz;
        reverse(val + 1, val + 1 + bit);
    }
    BigInteger(const BigInteger& rhs) {
        memset(val, 0, sizeof(val));
        bit = rhs.bit;
        for (int i = 1; i <= bit + 1; ++i) {
            val[i] = rhs.val[i];
        }
    }
    BigInteger& operator=(const BigInteger& rhs) {
        memset(val, 0, sizeof(val));
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

BigInteger operator+(const BigInteger& lhs, const BigInteger& rhs) {
    BigInteger c;
    c.bit = max(lhs.bit, rhs.bit);
    for (int i = 0; i <= c.bit; ++i) {
        if (i <= lhs.bit)
            c.val[i] += lhs.val[i];
        if (i <= rhs.bit)
            c.val[i] += rhs.val[i];
        c.val[i + 1] += c.val[i] / BASE;
        c.val[i] %= BASE;
    }
    if (c.val[c.bit + 1] != 0) c.bit++;
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
int num[maxm][maxm];
BigInteger dp[maxm][maxm];
BigInteger power[maxm];

int main() {
    power[0] = BigInteger(1);
    int m, n;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j<= m; ++j) {
            scanf("%d", &num[i][j]);
        }
    }
    for (int i = 1; i <= m; ++i) {
        power[i] = power[i - 1] * BigInteger(2);
    }
    
    
    BigInteger ans = 0;
    for (int h = 1; h <= n; ++h) {
        for (int i = 0; i <= m + 1; ++i) {
            for (int j = 0; j <= m + 1; ++j) {
                dp[i][j] = BigInteger(0);
            }
        }
        int* a = num[h];
        for (int k = m; k >= 1; --k) {
            int len = m - k + 1;
            for (int l = 1; l <= m - len + 1; ++l) {
                int r = l + len - 1;
                //do somthing on dp[l][r];
                dp[l][r] = max(dp[l + 1][r] + BigInteger(a[l]) * power[k],
                               dp[l][r - 1] + BigInteger(a[r]) * power[k]);
            }
        }
        ans = ans + dp[1][m];
    }
    cout << ans.toString() << endl;
    
    
    return 0;
}