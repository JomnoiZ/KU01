#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 35;
const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

char table[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> (table[i] + 1);
    }

    queue <pair <int, int>> q;
    q.emplace(1, 1);
    visited[1][1] = true;
    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int vx = ux + d[i][0], vy = uy + d[i][1];
            if (table[ux][uy] != table[vx][vy] and visited[vx][vy] == false) {
                visited[vx][vy] = true;
                q.emplace(vx, vy);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            ans += visited[i][j];
        }
    }
    cout << ans;
    return 0;
}