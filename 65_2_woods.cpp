#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 10;

vector <int> holes[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, W, L;
    cin >> N >> W >> L;

    for (int i = 1; i <= N; i++) {
        int K;
        cin >> K;

        while (K--) {
            int x;
            cin >> x;

            holes[i].push_back(x);
        }
    }

    bool success = false;
    for (int w = 1; w <= W; w++) {
        bool ok1 = true;
        for (int i = 1; i <= N; i++) {
            auto it = lower_bound(holes[i].begin(), holes[i].end(), w);

            bool ok2 = false;
            if (it != holes[i].end() and *it - w <= L) {
                ok2 = true;
            }
            if (it != holes[i].begin() and w - *(--it) <= L) {
                ok2 = true;
            }

            ok1 &= ok2;
        }
        success |= ok1;
    }
    cout << success;
    return 0;
}