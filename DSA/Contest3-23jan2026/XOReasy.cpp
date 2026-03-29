#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n + 1, 0);
        vector<bool> used(n + 1, false);
        p[n] = 1;
        used[1] = true;

        for (int i = 2; i <= n - 1; i++) {
            p[i] = i ^ 1;
            used[p[i]] = true;
        }
        for (int x = 1; x <= n; x++) {
            if (!used[x]) {
                p[1] = x;
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << p[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
