#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int L, N;
    cin >> L >> N;

    vector <pair <int, int>> bridges;
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;

        bridges.emplace_back(a, 1);
        bridges.emplace_back(b, -1);
    }

    sort(bridges.begin(), bridges.end());

    int ans = 0, cnt = 0;
    for (auto [p, v] : bridges) {
        cnt += v;
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}