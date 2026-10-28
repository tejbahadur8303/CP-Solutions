#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        string S;
        cin >> N >> S;

        int count = 1, ans = 0;

        for (int i = 1; i < N; i++) {
            if (S[i] == S[i - 1])
                count++;
            else
                count = 1;

            if (count == 3) {
                ans++;
                count = 0;
            }
        }

        cout << ans << endl;
    }

    return 0;
}