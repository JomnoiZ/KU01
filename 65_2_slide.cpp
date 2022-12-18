#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 305;

int X[MAX_N], id[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> X[i];

        id[X[i]] = i;
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if ((id[i] > id[j] and i > j) or (id[i] < id[j] and i < j)) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}