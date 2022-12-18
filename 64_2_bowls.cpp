#include <bits/stdc++.h>
using namespace std;

const int MAX_A = 305;

int cnt[MAX_A];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int a;
        cin >> a;

        cnt[a]++;
    }

    int max_repeat = 0;
    for (int i = 1; i <= 300; i++) {
        max_repeat = max(max_repeat, cnt[i]);
    }

    cout << max_repeat;
    return 0;
}