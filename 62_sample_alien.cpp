#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, a, b, R;
    cin >> N >> a >> b >> R;

    int ans = 0;
    while (N--) {
        int x, y;
        cin >> x >> y;

        if ((x - a) * (x - a) + (y - b) * (y - b) <= R * R) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}