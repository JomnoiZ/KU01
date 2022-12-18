#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

int X[MAX_N], Y[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int W, H, M, N;
    cin >> W >> H >> M >> N;

    X[0] = 0;
    for (int i = 1; i <= M; i++) {
        cin >> X[i];
    }
    X[M + 1] = W;

    Y[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> Y[i];
    }
    Y[N + 1] = H;

    vector <int> dX, dY;
    for (int i = 1; i <= M + 1; i++) {
        dX.push_back(X[i] - X[i - 1]);
    }
    for (int i = 1; i <= N + 1; i++) {
        dY.push_back(Y[i] - Y[i - 1]);
    }

    sort(dX.begin(), dX.end());
    sort(dY.begin(), dY.end());

    cout << dX.back() * dY.back() << ' ' << max(dX[dX.size() - 2] *  dY.back(), dX.back() * dY[dY.size() - 2]);
    return 0;
}