#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 305;

int A[MAX_N], B[MAX_N];
vector <int> graph[MAX_N];
bool need[MAX_N];

vector <int> dfs(int u) {
    vector <int> now;
    for (auto v : graph[u]) {
        vector <int> need = dfs(v);
        for (auto j : need) {
            now.push_back(j);
        }
    }
    if (need[u] == true or now.size() > 1) {
        return vector <int> ({u});
    }
    return now;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    vector <pair <int, int>> event;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];

        event.emplace_back(A[i], i);
        event.emplace_back(B[i] + 1, -i);
    }
    for (int i = 1; i <= M; i++) {
        int x;
        cin >> x;

        need[x] = true;
    }

    sort(event.begin(), event.end());

    stack <int> stk;
    stk.push(0);
    for (auto [p, v] : event) {
        if (v > 0) {
            graph[stk.top()].push_back(v);
            stk.push(v);
        }
        else {
            stk.pop();
        }
    }

    vector <int> ans;
    for (auto v : graph[0]) {
        vector <int> tmp = dfs(v);
        for (auto t : tmp) {
            ans.push_back(t);
        }
    }

    cout << ans.size() << '\n';
    for (auto v : ans) {
        cout << v << ' ';
    }
    return 0;
}