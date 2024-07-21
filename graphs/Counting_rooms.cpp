#include <bits/stdc++.h>
using namespace std;

void dfs(int i, int j, vector<vector<char>>& v) {
    if (i < 0 || j < 0 || i == v.size() || j == v[0].size() || v[i][j] == '#') {
        return;
    }
    else if (v[i][j] == '.') {
        v[i][j] = '#';
    }
    dfs(i + 1, j, v);
    dfs(i - 1, j, v);
    dfs(i, j + 1, v);
    dfs(i, j - 1, v);
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<char>> v(m, vector<char>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            v[i][j] = c;
        }
    }
    int rooms = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (v[i][j] == '.') {
                dfs(i, j, v);
                rooms++;
            }
        }
    }
    printf("%d", rooms);
    return 0;
}
