#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const int MAX_M = 1e5 + 5;

int required[MAX_M];
vector <pair <int, int>> graph[MAX_N];
bool visited[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        cin >> required[i];
        
        vector <int> need(required[i]);
        for (int j = 0; j < required[i]; j++) {
            cin >> need[j];
        }

        int T;
        cin >> T;

        for (int j = 0; j < required[i]; j++) {
            graph[need[j]].emplace_back(T, i);
        }
    }

    queue <int> q;
    q.push(1);
    visited[1] = true;
    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (auto [v, i] : graph[u]) {
            required[i]--;
            if (visited[v] == false and required[i] == 0) {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans += visited[i];
    }
    cout << ans;
    return 0;
}