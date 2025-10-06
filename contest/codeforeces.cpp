#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];

        int l = 0, r = n - 1;
        bool ok = true;
        for (int x = 1; x <= n; ++x) {
            if (l <= r && p[l] == x) {
                ++l;
            } else if (l <= r && p[r] == x) {
                --r;
            } else {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
