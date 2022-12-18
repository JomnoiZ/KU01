#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;
const int INF = 1e9 + 7;

int X[MAX_N], Y[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
    }

    int ans = INF;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int sum = 0;
            for (int k = 1; k <= N; k++) {
                sum += min(abs(X[i] - X[k]) + abs(Y[i] - Y[k]), abs(X[j] - X[k]) + abs(Y[j] - Y[k]));
            }
            ans = min(ans, sum);
        }
    }
    cout << ans;
    return 0;
}