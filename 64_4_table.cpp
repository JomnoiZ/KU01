#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;

int table[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int L, W, N;
    cin >> L >> W >> N;

    for (int i = 1; i <= N; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        for (int i = a + 1; i <= c; i++) {
            for (int j = b + 1; j <= d; j++) {
                table[i][j] = 1;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= L - 2; i++) {
        for (int j = 1; j <= W - 2; j++) {
            int cnt = 0;
            for (int k = 0; k <= 2; k++) {
                for (int l = 0; l <= 2; l++) {
                    cnt += table[i + k][j + l];
                }
            }

            if (cnt == 0) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}