#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;

vector <int> graph[MAX_N];
int dp[MAX_N];

int dfs(int u, int p) {
    if (dp[u] != 0) {
        return dp[u];
    }

    dp[u] = 1;
    for (auto v : graph[u]) {
        dp[u] += dfs(v, u);
    }
    return dp[u];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int l;
        cin >> l;

        while (l--) {
            int a, b;
            cin >> a >> b;

            if (b > 50) {
                graph[a].push_back(i);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, dfs(i, -1) - 1);
    }
    cout << ans;
    return 0;
}