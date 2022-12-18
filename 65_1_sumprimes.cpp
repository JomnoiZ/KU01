#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 15005;

bool is_prime[MAX_N];
vector <int> prime;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int A, B;
    cin >> A >> B;

    memset(is_prime, true, sizeof(is_prime));
    for (int i = 2; i <= 15000; i++) {
        if (is_prime[i] == true) {
            if (3 * A <= i and i <= 3 * B) {
                prime.push_back(i);
            }
            for (int j = 2 * i; j <= 15000; j += i) {
                is_prime[j] = false;
            }
        }
    }

    int ans = 0;
    for (auto p : prime) {
        for (int x = A; x <= B; x++) {
            int ub = (p - x) / 2;
            ans += max(0, min(ub - x + 1, B - ub + ((p - x) % 2 == 0)));
        }
    }
    cout << ans;
    return 0;
}