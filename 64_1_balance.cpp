#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

int ans;
int L[MAX_N], R[MAX_N];

int dfs(int u) {
    if (u < 0) {
        return -u;
    }

    int l = dfs(L[u]), r = dfs(R[u]);
    ans += abs(l - r);
    return 2 * max(l, r);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int A, B;
        cin >> A >> L[i] >> B >> R[i];

        if (A == 1) {
            L[i] *= -1;
        }
        if (B == 1) {
            R[i] *= -1;
        }
    }

    dfs(1);

    cout << ans;
    return 0;
}