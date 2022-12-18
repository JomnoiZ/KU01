#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 35;

int N, C;
int result[MAX_N][MAX_N];

int battle(int x, int y) {
    if (x == C and result[x][y] == y) {
        C = 0;
        return x;
    }
    if (y == C and result[x][y] == x) {
        C = 0;
        return y;
    }
    return result[x][y];
}

int findWinner(int l, int r) {
    if (r - l == 1) {
        return battle(l, r);
    }
    
    int mid = (l + r) / 2;
    return battle(findWinner(l, mid), findWinner(mid + 1, r));
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    cin >> N >> C;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> result[i][j];
        }
    }

    cout << findWinner(1, N);
    return 0;
}