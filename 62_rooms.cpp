#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 35;
const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

char table[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int R, C;
    cin >> R >> C;

    vector <pair <int, int>> warp;
    int sx, sy;
    for (int i = 1; i <= R; i++) {
        cin >> (table[i] + 1);

        for (int j = 1; j <= C; j++) {
            if (table[i][j] == 'A') {
                sx = i, sy = j;
            }
            else if (table[i][j] == 'W') {
                warp.emplace_back(i, j);
            }
        }
    }

    int ans = 0;
    queue <pair <int, int>> q;
    q.emplace(sx, sy);
    table[sx][sy] = '#';
    while (!q.empty()) {
        auto [ux, uy] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int vx = ux + d[i][0], vy = uy + d[i][1];
            if (vx < 1 or vx > R or vy < 1 or vy > C or table[vx][vy] == '#') {
                continue;
            }
            if (table[vx][vy] == 'W') {
                for (auto [vx, vy] : warp) {
                    if (table[vx][vy] == 'W') {
                        table[vx][vy] = '#';
                        q.emplace(vx, vy);
                    }
                }
            }
            else {
                ans += (table[vx][vy] == '*');
                q.emplace(vx, vy);
                table[vx][vy] = '#';
            }
        }
    }
    cout << ans;
    return 0;
}