#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const long long INF = 1e18 + 7;

long long S[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    long long minimum = INF;
    for (int i = 1; i <= N; i++) {
        cin >> S[i];

        minimum = min(minimum, S[i]);
    }

    int ans = N;
    for (int i = 1; i <= N; i++) {
        if (minimum * K <= (K - 1) * S[i]) {
            ans--;
        }
    }
    cout << ans;
    return 0;
}