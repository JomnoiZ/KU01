#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int H1, H2, B1, B2, X, Y;
    cin >> H1 >> H2 >> B1 >> B2 >> X >> Y;

    int ans = 0;
    for (int i = 0; i <= min(H1, B1); i++) {
        for (int j = 0; j <= min(H1, B2); j++) {
            for (int k = 0; k <= min(H2, B2); k++) {
                for (int l = 0; l <= min(H2, B1); l++) {
                    if (i + j > H1 or j + k > B2 or i + l > B1 or k + l > H2) {
                        break;
                    }
                    ans = max(ans, min(i + k, X) + min(j + l, Y));
                }
            }
        }
    }
    cout << ans;
    return 0;
}