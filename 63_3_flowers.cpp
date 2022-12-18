#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int L, N;
    cin >> L >> N;

    int ans;
    for (ans = 1;; ans++) {
        if (N <= ans * (ans + 1) / 2) {
            break;
        }
    }
    cout << (ans + L - 1) / L;
    return 0;
}