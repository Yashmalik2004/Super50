#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        long long totalSum = 0;
        for (long long x : a) {
            totalSum += x;
        }

        vector<long long> prefix(n);
        prefix[0] = a[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + a[i];
        }

        while (q--) {
            int l, r;
            long long k;
            cin >> l >> r >> k;

            l--;
            r--;

            long long rangeSum;
            if (l == 0)
                rangeSum = prefix[r];
            else
                rangeSum = prefix[r] - prefix[l - 1];

            long long newSum = totalSum - rangeSum + (r - l + 1) * k;

            if (newSum % 2)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }

    return 0;
}
