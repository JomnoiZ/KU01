#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1005;

int nxt[MAX_N];
bool visited[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, S;
    cin >> N >> S;

    for (int i = 1; i <= N; i++) {
        cin >> nxt[i];
    }

    int ans = 0;
    visited[0] = true;
    while (visited[S] == false) {
        visited[S] = true;
        S = nxt[S];
        ans++;
    }
    cout << ans;
    return 0;
}