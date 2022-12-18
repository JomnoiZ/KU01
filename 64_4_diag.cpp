#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int X[MAX_N], Y[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int x, y;
        cin >> x >> y;

        X[i] = x - y;
        Y[i] = x + y;
    }

    sort(X + 1, X + N + 1);
    sort(Y + 1, Y + N + 1);

    long long ans = 0;
    int midX = X[N / 2];
    int midY = Y[N / 2];
    for (int i = 1; i <= N; i++) {
        ans += abs(X[i] - midX) + abs(Y[i] - midY);
    }
    cout << ans;
    return 0;
}