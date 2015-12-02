#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <unordered_map>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1}; //0123 up down left right

int swap_space(int cur, int dir) {
    static int num[3][3];
    int x, y;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            num[i][j] = cur % 10;
            cur /= 10;
            if (num[i][j] == 0) x = i, y = j;
        }
    }
    
    int new_x = x + dx[dir], new_y = y + dy[dir];
    if (new_x < 0 || new_x > 2 || new_y < 0 || new_y > 2) {
        return 0;
    }
    swap(num[x][y], num[new_x][new_y]);
    
    int result = 0;
    for (int i = 2; i >= 0; --i) {
        for (int j = 2; j >= 0; --j) {
            result = result * 10 + num[i][j];
        }
    }
    return result;
}


int main() {
    int init_status = 87654321;
    unordered_map<int, pair<int, char> > mp;
    mp[init_status] = make_pair(0, 0);
    queue<int> q;
    q.push(init_status);
    
    while (!q.empty()) {
        int cur_status = q.front();
        q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int new_status = swap_space(cur_status, dir);
            if (new_status == 0) continue;
            if (mp.find(new_status) == mp.end()) {
                q.push(new_status);
                mp[new_status] = make_pair(cur_status, dir);
            }
        }
    }
    
    string line;
    while (getline(cin, line)) {
        istringstream str_stream(line);
        string str;
        vector<string> str_vec;
        while (str_stream >> str) {
            str_vec.push_back(str);
        }
        int val = 0, cur_val;
        reverse(str_vec.begin(), str_vec.end());
        for (int i = 0; i < str_vec.size(); ++i) {
            str = str_vec[i];
            if (str != "x") {
                cur_val = str[0] - '0';
            } else {
                cur_val = 0;
            }
            val = val * 10 + cur_val;
        }
#ifdef DEBUG
        cout << val << endl;
#endif
        int cur_status = val;
        if (mp.find(cur_status) == mp.end()) {
            puts("unsolvable");
            continue;
        }
        vector<int> ans_vec;
        while (cur_status != init_status) {
            pair<int, int> pr = mp[cur_status];
            ans_vec.push_back(pr.second);
            cur_status = pr.first;
        }
        string result;
        for (int i = 0; i < ans_vec.size(); ++i) {
            char dir = '\0';
            if (ans_vec[i] == 0) dir = 'd';
            if (ans_vec[i] == 1) dir = 'u';
            if (ans_vec[i] == 2) dir = 'r';
            if (ans_vec[i] == 3) dir = 'l';
            result.push_back(dir);
        }
        puts(result.c_str());
        
    }
    
    return 0;
}