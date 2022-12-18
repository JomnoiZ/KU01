#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    map <int, pair <int, int>> mp1, mp2;
    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;

        if (mp1.count(x - y)) {
            mp1[x - y] = make_pair(min(mp1[x - y].first, x), max(mp1[x - y].second, x));
        }
        else {
            mp1[x - y] = make_pair(x, x);
        }
        if (mp2.count(x + y)) {
            mp2[x + y] = make_pair(min(mp2[x + y].first, x), max(mp2[x + y].second, x));
        }
        else {
            mp2[x + y] = make_pair(x, x);
        }
    }

    int ans = 0;
    for (auto [k, v] : mp1) {
        ans = max(ans, v.second - v.first);
    }
    for (auto [k, v] : mp2) {
        ans = max(ans, v.second - v.first);
    }
    cout << ans;
    return 0;
}