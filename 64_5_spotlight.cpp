#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 725;

bool light[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int a, b;
        cin >> a >> b;
        b--;

        if (a > b) {
            b += 360;
        }
        for (int i = a; i <= b; i++) {
            light[i] = light[(i + 360) % 720] = true;
        }
    }

    int cnt = 0, ans = 0;
    for (int i = 0; i < 720; i++) {
        if (light[i] == true) {
            cnt++;
        }
        else {
            cnt = 0;
        }
        ans = max(ans, cnt);
    }
    cout << min(360, ans);
    return 0;
}