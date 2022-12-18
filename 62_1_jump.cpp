#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int L;
    string s;
    cin >> L >> s;

    int ans = L;
    for (int i = 0; i < L; i++) {
        if (s[i] == '#') {
            ans = min(ans, max(i, L - i - 1));
        }
    }
    cout << ans;
    return 0;
}