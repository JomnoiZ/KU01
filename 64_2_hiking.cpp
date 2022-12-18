#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, S;
    cin >> N >> S;

    int min_dist = S, max_dist = S;
    for (int i = 1; i <= N; i++) {
        int x;
        cin >> x;

        if (x % 12 == 0) {
            min_dist -= 10 * x / 3;
            max_dist -= 10 * x / 4;
        }
        else if (x % 3 == 0) {
            min_dist -= 10 * x / 3;
            max_dist -= 10 * x / 3;
        }
        else if (x % 4 == 0) {
            min_dist -= 10 * x / 4;
            max_dist -= 10 * x / 4;
        }
    }
    cout << min_dist << ' ' << max_dist;
    return 0;
}