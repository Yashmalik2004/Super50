#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<long long> a(n);
        for (auto &x : a) cin >> x;

        sort(a.begin(), a.end());

        vector<long long> pref(n + 1, 0), suff(n + 1, 0);

        for (int i = 1; i <= n; i++)
            pref[i] = pref[i - 1] + a[i - 1];

        for (int i = 1; i <= n; i++)
            suff[i] = suff[i - 1] + a[n - i];

        bool ok = false;
        for (int k = 2; k <= n - 1; k++) {
            if (suff[k - 1] > pref[k]) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
}
