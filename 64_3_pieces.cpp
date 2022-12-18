#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int X[MAX_N], Y[MAX_N];
map <int, int> cntX, cntY;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int L, W, N, M, Q;
    cin >> L >> W >> N >> M >> Q;

    X[N + 1] = L;
    Y[M + 1] = W;
    for (int i = 1; i <= N; i++) {
        cin >> X[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> Y[i];
    }

    for (int i = 1; i <= N + 1; i++) {
        cntX[X[i] - X[i - 1]]++;
    }
    for (int i = 1; i <= M + 1; i++) {
        cntY[Y[i] - Y[i - 1]]++;
    }

    while (Q--) {
        int A;
        cin >> A;

        int x = sqrt(A);
        long long ans = 0;
        for (int i = 1; i <= x; i++) {
            if (A % i == 0) {
                if (i != A / i) {
                    ans += 1ll * cntX[A / i] * cntY[i];
                }
                ans += 1ll * cntX[i] * cntY[A / i];
            }
        }
        cout << ans << '\n';
    }
    return 0;
}