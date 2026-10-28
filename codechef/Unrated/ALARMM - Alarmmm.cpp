#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, K;
        cin >> N >> K;

        string S;
        cin >> S;

        int ans = 0, i = 0;

        while (i < N) {
            if (S[i] == '1') {
                int p = min(N - 1, i + K);
                ans++;
                i = p + 1;
            } else {
                i++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}