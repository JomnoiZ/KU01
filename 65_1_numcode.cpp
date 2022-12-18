#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, T;
    cin >> N >> T;

    if (T == 1) {
        int py;
        cin >> py;

        if (py == N - 1) {
            cout << "0\n";
        }
        else {
            cout << "1\n";
        }
        for (int i = 2; i <= N; i++) {
            int y;
            cin >> y;

            if (y > py) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
            py = y;
        }
    }
    else {
        int y, py;
        cin >> py;
        
        if (py == N - 1) {
            cout << "0\n";
        }
        else {
            cout << "1\n";
        }
        for (int i = 2; i <= N; i++) {
            int z;
            cin >> z;

            if (z - py == py - 1 or z - py == py + 1) {
                y = z - py;
            }
            else {
                y = z - py * 2;
            }

            if (py > y) {
                cout << "0\n";
            }
            else {
                cout << "1\n";
            }

            py = y;
        }
    }
    return 0;
}