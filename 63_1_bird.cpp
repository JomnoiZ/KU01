#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

int H[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (H[i - 1] < H[i] and H[i] > H[i + 1]) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}