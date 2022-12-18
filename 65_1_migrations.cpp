#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 35;
const int d[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

char table[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int H, W, N;
    cin >> H >> W >> N;

    for (int i = 1; i <= H; i++) {
        cin >> (table[i] + 1);
    }

    while (N--) {
        int A, B, C, D, L;
        cin >> A >> B >> C >> D >> L;

        for (int i = 1; i <= H; i++) {
            for (int j = 1; j <= W; j++) {
                visited[i][j] = false;
            }
        }

        queue <pair <int, int>> q;
        q.emplace(A, B);
        visited[A][B] = true;
        while (!q.empty()) {
            auto [ux, uy] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int vx = ux + d[i][0], vy = uy + d[i][1];
                if (vx < 1 or vx > H or vy < 1 or vy > W or vx < A - L or vx > A + L or table[vx][vy] == '#') {
                    continue;
                }
                if (visited[vx][vy] == false) {
                    visited[vx][vy] = true;
                    q.emplace(vx, vy);
                }
            }
        }

        cout << visited[C][D] << '\n';
    }
    return 0;
}