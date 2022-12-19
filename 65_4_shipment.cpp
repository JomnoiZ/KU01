#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 305;
const int INF = 1e9 + 7;

int N, K;
int AtoX[2][MAX_N], XtoB[2][MAX_N];

int check(int x, int T) {
    int cnt = 0;
    for (int i = 1, j = N; i <= N and j >= 1; i++, j--) {
        while (j >= 1 and AtoX[x][i] + XtoB[x][j] > T) {
            j--;
        }
        if (j == 0) {
            break;
        }
        
        cnt++;
    }
    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> AtoX[0][i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> AtoX[1][i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> XtoB[0][i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> XtoB[1][i];
    }

    sort(AtoX[0] + 1, AtoX[0] + N + 1);
    sort(AtoX[1] + 1, AtoX[1] + N + 1);
    sort(XtoB[0] + 1, XtoB[0] + N + 1);
    sort(XtoB[1] + 1, XtoB[1] + N + 1);

    int l = 1, r = 2e6, ans;
    while (l <= r) {
        int mid = (l + r) / 2;

        if (check(0, mid) + check(1, mid) >= K) {
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