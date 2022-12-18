#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;

bool visited[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, K, T;
    cin >> N >> K >> T;
    T--;

    int u = 0, ans = 0;
    while (visited[u] == false) {
        ans++;
        if (u == T) {
            break;
        }
        visited[u] = true;
        u = (u + K) % N;
    }
    cout << ans;
    return 0;
}