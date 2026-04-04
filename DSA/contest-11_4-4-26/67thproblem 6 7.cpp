#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        vector<int> a(7);
        int sum = 0;
        for (int i = 0; i < 7; i++) {
            cin >> a[i];
            sum += a[i];
        }

        int mx = *max_element(a.begin(), a.end());

        cout << (2 * mx - sum) << '\n';
    }

    return 0;
}