#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 35;

char table[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> (table[i] + 1);
    }

    queue <pair <int, int>> q;
    q.emplace(N, N);
    table[N][N] = 'K';
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        if (x - 1 >= 1 and table[x - 1][y] == '.') {
            table[x - 1][y] = 'K';
            q.emplace(x - 1, y);
        }
        if (y - 1 >= 1 and table[x][y - 1] == '.') {
            table[x][y - 1] = 'K';
            q.emplace(x, y - 1);
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += (table[i][j] == 'K');
        }
    }

    cout << ans;
    return 0;
}