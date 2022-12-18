#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int L, N;
    cin >> L >> N;

    int ans;
    for (ans = 1; ans <= L; ans++) {
        N -= ans * ans;
        if (N < 0) {
            break;
        }
    }
    cout << L - ans + 1;
    return 0;
}