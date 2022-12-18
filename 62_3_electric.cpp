#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, L;
    cin >> N >> L;

    int ans = INF;
    for (int i = 1; i <= N; i++) {
        int p = 0, power = 0;
        for (int j = 1; j <= L; j++) {
            int a;
            cin >> a;

            power = max(power, a - p);
            p = a;
        }
        ans = min(ans, power);
    }
    cout << ans;
    return 0;
}