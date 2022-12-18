#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

int A[MAX_N];
bool visited[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        if (visited[i] == true) {
            continue;
        }

        int u = i, cnt = 0;
        while (visited[u] == false) {
            cnt++;
            visited[u] = true;
            u = A[u];
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}