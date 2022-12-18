#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 5e4 + 5;
const int MAX_H = 1e5 + 5;

int R[MAX_N];
int blue[MAX_H], red[MAX_H], qs_blue[MAX_H], qs_red[MAX_H];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> R[i];
    }

    for (int i = 2; i <= N; i++) {
        int a = min(R[i - 1], R[i]), b = max(R[i - 1], R[i]), l, r;
        
        l = a + 1 + ((a + 1) % 2 == 0);
        r = b - 1 - ((b - 1) % 2 == 0);

        if (l <= r) {
            blue[l]++;
            blue[r + 1]--;
        }

        l = a + 1 + ((a + 1) % 2 == 1);
        r = b - 1 - ((b - 1) % 2 == 1);

        if (l <= r) {
            red[l]++;
            red[r + 1]--;
        }
    }

    for (int i = 1; i < MAX_H; i++) {
        red[i] += red[i - 1];
        blue[i] += blue[i - 1];

        qs_blue[i] = qs_blue[i - 1];
        qs_red[i] = qs_red[i - 1];
        if (i % 2 == 1) {
            qs_blue[i] += blue[i];
        }
        else {
            qs_red[i] += red[i];
        }
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int L, H;
        cin >> L >> H;

        cout << qs_red[H] - qs_red[L - 1] << ' ' << qs_blue[H] - qs_blue[L - 1] << '\n';
    }
    return 0;
}