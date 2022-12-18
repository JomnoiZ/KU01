#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int C[MAX_N];
int cnt[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> C[i];
    }

    int sum = 0;
    long long ans = 0;
    for (int l = 1, r = 1; l <= N; l++) {
        while (r <= N and sum < K) {
            if (cnt[C[r]]++ == 0) {
                sum++;
            }
            r++;
        }

        ans += (N - r + 2) * (sum >= K);
        
        if (--cnt[C[l]] == 0) {
            sum--;
        }
    }
    cout << ans;
    return 0;
}