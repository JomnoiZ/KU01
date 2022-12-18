#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, L;
    cin >> N >> L;

    vector <pair <int, int>> trucks;
    for (int i = 1; i <= N; i++) {
        int s, t;
        cin >> s >> t;

        trucks.emplace_back(t, s);
    }

    sort(trucks.begin(), trucks.end());

    int furthest = -1, ans = 0;
    for (auto [t, s] : trucks) {
        if (furthest >= s) {
            continue;
        }
        if (furthest < t) {
            ans++;
            furthest = t;
        }
    }
    cout << ans;
    return 0;
}