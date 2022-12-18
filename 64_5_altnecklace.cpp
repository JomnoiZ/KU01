#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    long long N;
    int M, K;
    cin >> N >> M >> K;
    
    int ans = M;
    vector <long long> X;
    X.push_back(1);
    while (M--) {
        long long x;
        cin >> x;

        X.push_back(x);
    }
    X.push_back(N + 1);

    while (K--) {
        long long a;
        int c;
        cin >> a >> c;

        auto it = upper_bound(X.begin(), X.end(), a);
        if (a == N and (it - X.begin() + 1) % 2 == c) {
            ans++;
        }
        else if (a + 1 != *it and (it - X.begin() + 1) % 2 == c) {
            ans += 2;
        }
    }
    cout << ans;
    return 0;
}