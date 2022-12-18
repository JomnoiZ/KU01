#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 355;
const int MAX_P = 2e5 + 5;
const int INF = 1e9 + 7;

int table[MAX_N][MAX_N];
map <int, tuple <int, int, int, int>> plants;
int ans[MAX_P][2];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int H, W, Q;
    cin >> H >> W >> Q;

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> table[i][j];

            if (plants.count(table[i][j])) {
                auto [mii, mij, mai, maj] = plants[table[i][j]];
                mii = min(mii, i);
                mij = min(mij, j);
                mai = max(mai, i);
                maj = max(maj, j);
                plants[table[i][j]] = make_tuple(mii, mij, mai, maj);
            }
            else {
                plants[table[i][j]] = make_tuple(i, j, i, j);
            }
        }
    }

    int mii = INF, mij = INF, mai = -INF, maj = -INF;
    for (int k = 2e5; k >= 0; k--) {
        ans[k][1] = ans[k + 1][1];
        if (plants.count(k)) {
            auto [mix, miy, maX, may] = plants[k];
            ans[k][0] = 2 * ((maX - mix + 1) + (may - miy + 1));
            
            mii = min(mii, mix);
            mij = min(mij, miy);
            mai = max(mai, maX);
            maj = max(maj, may);
            ans[k][1] = 2 * ((mai - mii + 1) + (maj - mij + 1));
        }
    }

    while (Q--) {
        int A, B;
        cin >> A >> B;

        cout << ans[B][A - 1] << '\n';
    }
    return 0;
}