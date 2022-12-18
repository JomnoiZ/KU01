#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N, x;
    cin >> N;

    x = sqrt(N - 1);
    cout << x * 2 - ((N - x * x) % 2 == 0);
    return 0;
}