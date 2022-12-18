#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 505;

int a[MAX_N], b[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> b[i];
    }

    int ans = 1;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (a[i] == b[j]) {
                ans++;
            }
            else if (j % 2 == i % 2) {
                if ((a[i] < b[j] and a[i - 1] > b[j - 1]) or (a[i] > b[j] and a[i - 1] < b[j - 1])) {
                    ans++;
                }
            }
            else {
                if ((a[i] < b[j - 1] and a[i - 1] > b[j]) or (a[i] > b[j - 1] and a[i - 1] < b[j])) {
                    ans++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}