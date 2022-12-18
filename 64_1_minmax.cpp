#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 35;
const int INF = 1e9 + 7;

int A[MAX_N][MAX_N];
int max_val[MAX_N], min_val[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, B;
    cin >> N >> B;

    int maximum = -INF, minimum = INF;
    for (int i = 1; i <= N; i++) {
        max_val[i] = -INF, min_val[i] = INF;
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];

            maximum = max(maximum, A[i][j]);
            minimum = min(minimum, A[i][j]);
            max_val[i] = max(max_val[i], A[i][j]);
            min_val[i] = min(min_val[i], A[i][j]);
        }
    }

    int ans = maximum - minimum;
    for (int r1 = 1; r1 <= N; r1++) {
        for (int r2 = r1 + 1; r2 <= N; r2++) {
            ans = max(ans, max(max_val[r1] - min_val[r2], max_val[r2] - min_val[r1]) + 2 * B);
        }
    }
    cout << ans;
    return 0;
}