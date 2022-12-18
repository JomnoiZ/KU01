#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

int X[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    int now = 0;
    for (int i = 1; i <= N; i++) {
        cin >> X[i];
    }

    while (M--) {
        int x;
        cin >> x;

        now += x;
        now = min(now, N);
        if (now == N) {
            break;
        }
        now += X[now];
        now = max(now, 0);
        now = min(now, N);
        if (now == N) {
            break;
        }
    }
    cout << now;
    return 0;
}