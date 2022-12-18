#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5 + 5;

int p[MAX_N], v[MAX_N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;
    
    vector <pair <int, int>> cars;
    for (int i = 1; i <= N; i++) {
        cin >> p[i] >> v[i];

        cars.emplace_back(p[i], v[i]);
    }

    sort(cars.begin(), cars.end());

    int efficiency = cars[0].second, cnt = N - 1;
    for (int i = 1; i < cars.size(); i++) {
        if (efficiency < cars[i].second) {
            efficiency = cars[i].second;
            cnt--;
        }
    }
    cout << cnt;
    return 0;
}