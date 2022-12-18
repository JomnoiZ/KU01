#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

int X[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> X[i];
    }

    sort(X + 1, X + N + 1);

    priority_queue <int, vector <int>, greater <int>> pq;
    for (int i = 1; i <= 200; i++) {
        pq.push(i);
        for (int j = 0; j < 9; j++) {
            pq.push(2 * i);
        }
    }

    int ans = 0;
    for (int i = N; i >= 1; i--) {
        ans += pq.top() * X[i];
        pq.pop();
    }
    cout << ans;
    return 0;
}