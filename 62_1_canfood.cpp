#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;

        if (a <= 400 and 150 <= b and b <= 200) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}