#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 25;

int sum_row[MAX_N], sum_col[MAX_N];
int table[MAX_N][MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> sum_row[i];
    }
    for (int i = 1; i <= N; i++) {
        cin >> sum_col[i];
    }

    for (int j = 1; j <= N; j++) {
        for (int i = 1; i <= N; i++) {
            if (sum_row[i] >= sum_col[j]) {
                sum_row[i] -= sum_col[j];
                table[i][j] = sum_col[j];
                break;
            }
            else {
                sum_col[j] -= sum_row[i];
                table[i][j] = sum_row[i];
                sum_row[i] = 0;
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << table[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}