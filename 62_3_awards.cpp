#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 305;

int A[MAX_N * 2];
bool contained[MAX_N * 2];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int N;
    cin >> N;

    vector <int> vec;
    for (int i = 1; i <= 2 * N; i++) {
        cin >> A[i];

        contained[A[i]] = true;
    }

    for (int i = 2 * N; i >= 1; i--) {
        if (contained[i] == false) {
            vec.push_back(i);
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        int k = 0, sum = 0;
        for (int j = 1; j <= i; j++) {
            if (A[j] == 0) {
                sum += vec[k++];
            }
            else {
                sum += A[j];
            }
        }
        for (int j = N + i; j <= 2 * N; j++) {
            if (A[j] == 0) {
                sum += vec[k++];
            }
            else {
                sum += A[j];
            }
        }
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}