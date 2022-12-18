#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector <pair <int, int>> factories;
    while (M--) {
        int S, T;
        cin >> S >> T;

        factories.emplace_back(S, 1);
        factories.emplace_back(T + 1, -1);
    }

    sort(factories.begin(), factories.end());

    int cnt = 0, ans = 0;
    for (auto [p, v] : factories) {
        cnt += v;
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}