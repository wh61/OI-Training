#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

const int maxn = 120000;
char str_buffer1[100], str_buffer2[100];

using namespace std;


void split(const string& s, char c,
           vector<string>& v) {
    string::size_type i = 0;
    string::size_type j = s.find(c);
    
    while (j != string::npos) {
        v.push_back(s.substr(i, j - i));
        i = ++j;
        j = s.find(c, j);
        
        if (j == string::npos)
            v.push_back(s.substr(i, s.length()));
    }
}


int string2int(const string& str) {
    int val = 0;
    for (int i = 0; i < str.size(); ++i) {
        val = val * 10 + str[i] - '0';
    }
    return val;
}

struct node {
    void init(int val_ = 0) {
        index = -1;
        val = val_;
        memset(next, NULL, sizeof(next));
    }
    int val, index;
    node* next[2];
}nodes[maxn * 32];

int e = 0;
node* _alloc() {
    nodes[e].init();
    return &nodes[e++];
}

const int inf = 1000000000;


struct Trie {
    node* root;
    void init() {
        e = 0;
        root = _alloc();
    }
    void insert(const vector<int>& vec, int type, int index) {
        int sz = vec.size();
        node* rt = root;
        for (int i = 0; i < sz; ++i) {
            int val = vec[i];
            if (rt->next[val] == NULL) {
                rt->next[val] = _alloc();
            }
            rt = rt->next[val];
        }
        if (rt->val == 0) {
            rt->val = type;
            rt->index = index;
        }
    }
    bool find(const vector<int>& vec) {
        int sz = vec.size();
        node* rt = root;
        int index = inf;
        int type = 0;
        if (rt->val != 0) {
            if (rt->index < index) {
                index = rt->index;
                type = rt->val;
            }
        }
        for (int i = 0; i < sz; ++i) {
            int val = vec[i];
            if (rt->next[val] == NULL) {
                break;
            }
            rt = rt->next[val];
            if (rt->val != 0 && rt->index < index) {
                index = rt->index;
                type = rt->val;
            }
        }
        if (type == -1) return false;
        return true;
    }
}trie;



int main() {
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        trie.init();
        for (int i = 0; i < n; ++i) {
            scanf("%s %s", str_buffer1, str_buffer2);
            string str1 = str_buffer1, str2 = str_buffer2;
            int type = 1;
            if (str1 == "deny") type = -1;
            vector<string> s_vec;
            split(str2, '/', s_vec);
            if (s_vec.size() < 2) {
                s_vec.push_back(str2);
                s_vec.push_back("32");
            }
            vector<string> num_strings;
            split(s_vec[0], '.', num_strings);
            vector<int> bits;
            for (int i = 0; i < num_strings.size(); ++i) {
                int val = string2int(num_strings[i]);
                for (int j = 7; j >= 0; --j) {
                    bits.push_back((val >> j) & 1);
                }
            }
            int bit_mask = string2int(s_vec[1]);
            vector<int> vec_;
            for (int i = 0; i < bit_mask; ++i) {
                vec_.push_back(bits[i]);
            }
            trie.insert(vec_, type, i);
        }
        for (int i = 0; i < m; ++i) {
            scanf("%s", str_buffer1);
            string str = str_buffer1;
            vector<string> num_strings;
            split(str, '.', num_strings);
            vector<int> bits;
            for (int i = 0; i < num_strings.size(); ++i) {
                int val = string2int(num_strings[i]);
                for (int j = 7; j >= 0; --j) {
                    bits.push_back((val >> j) & 1);
                }
            }
            bool ans = trie.find(bits);
            if (ans) {
                puts("YES");
            }
            else {
                puts("NO");
            }
        }
    }
    return 0;
}