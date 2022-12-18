#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

int A[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    sort(A + 1, A + N + 1);

    int sum = 0, ans = 0;
    for (int i = 1; i <= N; i++) {
        sum += A[i];
        ans += sum * 2;
    }
    cout << ans;
    return 0;
}