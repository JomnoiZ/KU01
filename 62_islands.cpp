#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;

int A[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    int cnt = 0;
    vector <int> need;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];

        if (A[i] < 0) {
            cnt += -A[i] + 1;
        }
        else if (cnt > 0) {
            need.push_back(cnt);
            cnt = 0;
        }
    }
    need.push_back(cnt);

    sort(need.begin(), need.end());

    int ans = 0;
    for (int i = 0; i < need.size() - K - 1; i++) {
        ans += need[i];
    }
    cout << ans;
    return 0;
}