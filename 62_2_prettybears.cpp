#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    int ans = 0;
    while (N--) {
        int a, b;
        cin >> a >> b;

        if (100 <= a and a <= 750 and b >= 80) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}