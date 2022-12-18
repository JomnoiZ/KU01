#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int L, M, N;
    cin >> L >> M >> N;

    for (int i = 1; i <= N; i++) {
        int now = L;
        bool survive = true;
        for (int j = 1; j <= M; j++) {
            int a;
            cin >> a;

            if (a == 0) {
                a = -1;
            }
            now += a;

            if (now == -1 or now == 2 * L + 1) {
                survive = false;
            }
        }
        cout << survive << '\n';
    }
    return 0;
}