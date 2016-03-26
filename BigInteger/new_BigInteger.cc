
#include <vector>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

const int BASE = 10;
struct BigInteger {
    vector<int> s;
    BigInteger(long long num = 0) {
        s.clear();
        if (num == 0) s.push_back(0);
        while (num != 0) {
            s.push_back(num % BASE);
            num /= BASE;
        }
    }
    BigInteger(string str) {
        reverse(str.begin(), str.end());
        s.clear();
        int len = str.length();
        for (int i = 0; i < len; ++i) {
            s.push_back(str[i] - '0');
        }
    }
    string toString() {
        string str;
        int len = s.size();
        for (int i = 0 ; i < len; ++i) {
            str.push_back('0' + s[i]);
        }
        reverse(str.begin(), str.end());
        return str;
    }
};

BigInteger operator*(const BigInteger& lhs, const BigInteger& rhs) {
    BigInteger ans;
    ans.s.clear();
    int left_len = lhs.s.size(), right_len = rhs.s.size();
    ans.s.assign(left_len + right_len, 0);
    for (int i = 0; i < left_len; ++i) {
        for (int j = 0; j < right_len; ++j) {
            ans.s[i + j] += lhs.s[i] * rhs.s[j];
            ans.s[i + j + 1] += ans.s[i + j] / BASE;
            ans.s[i + j] %= BASE;
        }
    }
    while (ans.s.size() > 1 && ans.s.back() == 0) ans.s.pop_back();
    return ans;
}

BigInteger operator+(const BigInteger& lhs, const BigInteger& rhs) {
    BigInteger ans;
    ans.s.clear();
    int left_len = lhs.s.size(), right_len = rhs.s.size();
    ans.s.assign(max(left_len, right_len) + 1, 0);
    
    for (int i = 0; i < max(left_len, right_len); ++i) {
        int lhs_val = 0, rhs_val = 0;
        if (i < left_len) lhs_val = lhs.s[i];
        if (i < right_len) rhs_val = rhs.s[i];
        ans.s[i] += lhs_val + rhs_val;
        ans.s[i + 1] += ans.s[i] / BASE;
        ans.s[i + 1] /= BASE;
    }
    
    while (ans.s.size() > 1 && ans.s.back() == 0) ans.s.pop_back();
    return ans;
}

bool operator<(const BigInteger& lhs, const BigInteger& rhs) {
    if (lhs.s.size() != rhs.s.size()) {
        return lhs.s.size() < rhs.s.size();
    }
    int len = lhs.s.size();
    for (int i = len - 1; i >= 0; --i) {
        if (lhs.s[i] != rhs.s[i]) {
            return lhs.s[i] < rhs.s[i];
        }
    }
    return false;
}

bool operator==(const BigInteger& lhs, const BigInteger& rhs) {
    return (!(lhs < rhs) && !(rhs < lhs));
}

bool operator<=(const BigInteger& lhs, const BigInteger& rhs) {
    return lhs < rhs || lhs == rhs;
}

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    BigInteger num1(str1), num2(str2);
    // cout << num1.toString() << ' ' << num2.toString() << endl;
    BigInteger ans = num1 * num2;
    // cout << num1.toString() << ' ' << num2.toString() << endl;
    cout << ans.toString() << endl;
    return 0;
}

