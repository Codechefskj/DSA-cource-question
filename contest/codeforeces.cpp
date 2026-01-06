#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> temp(n), temp1(n), temp2(n);
        for (int i = 0; i < n; i++) cin >> temp[i];
        for (int i = 0; i < n; i++) cin >> temp1[i];
        for (int i = 0; i < n; i++) cin >> temp2[i];

        vector<int> A(3*n), B(3*n), C(3*n);
        for (int i = 0; i < 3*n; i++) {
            A[i] = temp[i % n];
            B[i] = temp1[i % n];
            C[i] = temp2[i % n];
        }

        vector<vector<char>> ab(n, vector<char>(n, 0));
        vector<vector<char>> bc(n, vector<char>(n, 0));

        for (int j = 0; j < n; j++) {
            vector<int> bad(3*n, 0);
            for (int i = 0; i < 3*n; i++) {
                if (A[i] >= B[i + j]) bad[i] = 1;
            }

            vector<int> pref(3*n + 1, 0);
            for (int i = 0; i < 3*n; i++)
                pref[i + 1] = pref[i] + bad[i];

            for (int i = 0; i < n; i++) {
                if (pref[i + n] - pref[i] == 0)
                    ab[i][j] = 1;
            }
        }

        for (int k = 0; k < n; k++) {
            vector<int> bad(3*n, 0);
            for (int j = 0; j < 3*n; j++) {
                if (B[j] >= C[j + k]) bad[j] = 1;
            }

            vector<int> pref(3*n + 1, 0);
            for (int j = 0; j < 3*n; j++)
                pref[j + 1] = pref[j] + bad[j];

            for (int j = 0; j < n; j++) {
                if (pref[j + n] - pref[j] == 0)
                    bc[j][k] = 1;
            }
        }

        long long ans = 0;

        for (int j = 0; j < n; j++) {
            long long cnt1 = 0, cnt2 = 0;

            for (int i = 0; i < n; i++)
                if (ab[i][j]) cnt1++;

            for (int k = 0; k < n; k++)
                if (bc[j][k]) cnt2++;

            ans += cnt1 * cnt2;
        }

        cout << ans << "\n";
    }

    return 0;
}
