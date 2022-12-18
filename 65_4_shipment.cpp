#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 305;
const int INF = 1e9 + 7;

int N, K;
int AtoX[2 * MAX_N], XtoB[2 * MAX_N], idx[2 * MAX_N];
bool used[2 * MAX_N][2 * MAX_N];

bool check(int T) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            used[i][j] = false;
            used[i + N][j + N] = false;
        }
    }

    int cnt = 0, cost;
    while (cnt < K) {
        int maximum = 0, max2 = 0;
        int u = -1, v = -1;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (used[i][j] == false) {
                    cost = AtoX[i] + XtoB[j];
                    if (cost <= T and maximum < cost) {
                        maximum = cost, max2 = XtoB[j];
                        u = i, v = j;
                    }
                    else if (maximum == cost and max2 < XtoB[j]) {
                        max2 = XtoB[j];
                        u = i, v = j;
                    }
                }
                if (used[i + N][j + N] == false) {
                    cost = AtoX[i + N] + XtoB[j + N];
                    if (cost <= T and maximum < cost) {
                        maximum = cost;
                        u = i + N, v = j + N;
                    }
                    else if (maximum == cost and max2 < XtoB[j + N]) {
                        max2 = XtoB[j + N];
                        u = i + N, v = j + N;
                    }
                }
            }
        }

        if (u == -1 and v == -1) {
            break;
        }
        
        cnt++;
        int add = (u > N) * N;
        for (int i = 1; i <= N; i++) {
            used[u][i + add] = true;
            used[i + add][v] = true;
        }
    }
    return cnt >= K;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> N >> K;

    for (int i = 1; i <= 2 * N; i++) {
        cin >> AtoX[i];
    }
    for (int i = 1; i <= 2 * N; i++) {
        cin >> XtoB[i];
    }

    iota(idx + 1, idx + 2 * N + 1, 1);
    sort(idx + 1, idx + 2 * N + 1, [&](const int &a, const int &b) {
        return AtoX[a] < AtoX[b];
    });

    int l = 1, r = 2e6, ans;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (check(mid) == true) {
            ans = mid;
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    cout << ans;
    return 0;
}