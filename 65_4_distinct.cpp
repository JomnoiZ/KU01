#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 105;

int p[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }

    set <int> possible;
    for (int i = 1; i <= N; i++) {
        int sum = 0;
        for (int j = i; j <= N; j++) {
            sum += p[j];
            possible.insert(sum);
        }
    }
    cout << possible.size();
    return 0;
}