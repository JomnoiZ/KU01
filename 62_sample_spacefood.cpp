#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    int sum = 0, ans = 0;
    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;

        sum += a;
        if (sum < M) {
            ans = -1;
            break;
        }
        else if (sum < K) {
            sum = 0;
            ans++;
        }
        else if (sum >= K) {
            sum -= K;
        }
    }
    cout << ans;
    return 0;
}