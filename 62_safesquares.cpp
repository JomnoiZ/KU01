#include <bits/stdc++.h>
using namespace std;

const int MOD = 25621;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;
    
    set <int> X, Y;
    while (K--) {
        int x, y;
        cin >> x >> y;

        if (!X.count(x)) {
            X.insert(x);
            N--;
        }
        if (!Y.count(y)) {
            Y.insert(y);
            M--;
        }
    }
    cout << 1ll * N * M % MOD;
    return 0;
}