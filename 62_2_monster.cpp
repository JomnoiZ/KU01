#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, H;
    cin >> N >> H;

    int ans = 0;
    while (N--) {
        int a;
        cin >> a;

        if (a <= H) {
            ans = max(ans, a);
        }
    }
    cout << ans;
    return 0;
}