#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;

char table[MAX_N][MAX_N];
int rows[MAX_N], cols[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> (table[i] + 1);

        for (int j = 1; j <= N; j++) {
            rows[i] += (table[i][j] == '#');
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= rows[i]; j++) {
            cols[j]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (N - cols[j] + 1 <= i) {
                cout << '#';
            }
            else {
                cout << '.';
            }
        }
        cout << '\n';
    }
    return 0;
}