#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= N; i++) {
        int h;
        cin >> h;

        if (h > 18) {
            cnt1++;
        }
        else {
            cnt2++;
        }
    }

    cout << cnt1 + cnt2 + max(0, cnt1 - cnt2 - 1);
    return 0;
}