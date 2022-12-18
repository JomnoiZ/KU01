#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int W, L, M, N;
    cin >> W >> L >> M >> N;

    int ans = INF;
    for (int A = M; A <= N; A++) {
        ans = min(ans, (W % A) * (L % A));
    }
    cout << ans;
    return 0;
}