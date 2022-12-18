#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int H[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, L;
    cin >> N >> L;

    for (int i = 1; i <= N; i++) {
        cin >> H[i];
    }

    int max_height = 0;
    for (int i = 1, j = 1; i <= L; i++) {
        int a;
        cin >> a;

        while (j < a) {
            max_height = max(max_height, H[j]);
            j++;
        }

        cout << max(0, max_height - H[a] + 1) << '\n';
    }
    return 0;
}