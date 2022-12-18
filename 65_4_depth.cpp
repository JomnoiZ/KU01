#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5;
const int INF = 1e9 + 7;

int D[MAX_N], L[MAX_N];
vector <pair <int, int>> depth[MAX_N];
int parent[MAX_N], length[MAX_N];
bool visited[MAX_N];

int find_parent(int u) {
    if (u == parent[u]) {
        return u;
    }
    return parent[u] = find_parent(parent[u]);
}

void merge(int u, int v) {
    u = find_parent(u), v = find_parent(v);
    if (u == v) {
        return;
    }

    parent[v] = u;
    L[u] += L[v];
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, Q;
    cin >> N >> Q;

    int max_depth = 0;
    for (int i = 1; i <= N; i++) {
        cin >> D[i] >> L[i];

        D[i] += D[i - 1];
        depth[D[i]].emplace_back(L[i], i);
        max_depth = max(max_depth, D[i]);
        parent[i] = i;
    }

    int max_length = 0;
    vector <pair <int, int>> vec;
    for (int d = max_depth; d >= 1; d--) {
        for (auto [l, i] : depth[d]) {
            visited[i] = true;
            if (i - 1 >= 1 and visited[i - 1] == true) {
                merge(i - 1, i);
            }
            if (i + 1 <= N and visited[i + 1] == true) {
                merge(i, i + 1);
            }
            max_length = max(max_length, L[find_parent(i)]);
        }
        vec.emplace_back(max_length, d);
    }
    vec.emplace_back(INF, 0);

    while (Q--) {
        int l;
        cin >> l;

        auto it = lower_bound(vec.begin(), vec.end(), make_pair(l, -1));
        cout << it->second << '\n';
    }
    return 0;
}