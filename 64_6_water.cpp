#include <bits/stdc++.h>
using namespace std;

const int MAX_L = 4005;

long long water[MAX_L];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, L, X;
    cin >> N >> L >> X;

    if (X == 1) {
        water[X + 1] = 2;
    }
    else if (X == 2 * L - 1) {
        water[X - 1] = 2;
    }
    else {
        water[X - 1] = water[X + 1] = 1;
    }
    for (int i = 2; i <= N; i++) {
        if (i % 2 == 1) {
            for (int j = 2; j <= 2 * L - 2; j += 2) {
                water[j] = water[j - 1] + water[j + 1];   
            }
            water[2] += water[1];
            water[2 * L - 2] += water[2 * L - 1];
        }
        else {
            for (int j = 1; j <= 2 * L - 1; j += 2) {
                water[j] = water[j - 1] + water[j + 1];
            }
        }
    }

    if (N % 2 == 0) {
        for (int i = 1; i <= 2 * L - 1; i += 2) {
            cout << water[i] << ' ';
        }
    }
    else {
        for (int i = 2; i <= 2 * L - 2; i += 2) {
            cout << water[i] << ' ';
        }
    }
    return 0;
}