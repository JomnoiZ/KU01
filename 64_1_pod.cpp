#include <bits/stdc++.h>
using namespace std;

const int MAX_K = 305;

int pods[MAX_K];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    int cnt = 0, ans = N;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;

        if (pods[x] == 0) {
            cnt++;
        }
        pods[x]++;

        if (cnt == K) {
            ans -= K;
            for (int k = 1; k <= K; k++) {
                pods[k]--;
                if (pods[k] == 0) {
                    cnt--;
                }
            }
        }
    }
    cout << ans;
    return 0;
}