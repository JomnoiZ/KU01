#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int L, W;
        cin >> L >> W;

        if (W * 100 <= L * 75) {
            ans += 5;
        }
        else {
            ans += 3;
        }
    }
    cout << ans;
    return 0;
}