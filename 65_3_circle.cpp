#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 305;

int a[MAX_N], b[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    a[0] = 1, b[0] = 1;
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> b[i];
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        set <int> s;
        for (int j = a[i - 1] % N + 1; j != a[i]; j = j % N + 1) {
            s.insert(j);
        }
        set <int> t;
        for (int j = a[i] % N + 1; j != a[i - 1]; j = j % N + 1) {
            t.insert(j);
        }

        if (s.count(b[i - 1]) != s.count(b[i]) and t.count(b[i - 1]) != t.count(b[i])) {
            ans++;
        }
        else if(min(b[i - 1], b[i]) == min(a[i - 1], a[i]) and max(b[i - 1],  b[i]) == max(a[i - 1], a[i])) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}