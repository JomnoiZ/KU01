#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 55;

int A[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int W, L;
    cin >> W >> L;

    for (int i = 1; i <= W; i++) {
        for (int j = 1; j <= L; j++) {
            cin >> A[i][j];
        }
    }

    int ans = 0;
    for (int i = 1; i <= W - 4; i++) {
        for (int j = 1; j <= L - 4; j++) {
            bool chk[10] = {};
            for (int x = 0; x < 5; x++) {
                for (int y = 0; y < 5; y++) {
                    chk[A[i + x][j + y]] = true;
                }
            }

            int cnt = 0;
            for (int a = 0; a < 10; a++) {
                cnt += chk[a];
            }

            if (cnt >= 5) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}