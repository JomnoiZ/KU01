#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 25;

int highest[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M, S;
    cin >> N >> M >> S;

    int ans = N * M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int a;
            cin >> a;

            if (a + i * S <= highest[j]) {
                ans--;
            }
            highest[j] = max(highest[j], a + i * S);
        }
    }
    cout << ans;
    return 0;
}