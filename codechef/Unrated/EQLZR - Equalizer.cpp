
#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<long long> A(N);
        for (int i = 0; i < N; i++)
            cin >> A[i];

        int score = 0;
        for (int i = 0; i < N - 1; i++)
            if (A[i] == A[i + 1])
                score++;

        int ans = 0, bestLeft = 0;

        for (int R = 0; R < N; R++) {
            int left = 0, right = 0;

            if (R > 0) {
                left = (A[R - 1] == A[R] + 1)
                     - (A[R - 1] == A[R]);
            }

            bestLeft = max(bestLeft, left);

            if (R < N - 1) {
                right = (A[R] + 1 == A[R + 1])
                      - (A[R] == A[R + 1]);
            }

            ans = max(ans, bestLeft + right);
        }

        cout << score + ans << '\n';
    }

    return 0;
}
