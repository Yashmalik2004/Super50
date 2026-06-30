#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int transitions = 0;
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1])
                transitions++;
        }

        if (transitions == 0)
            cout << 1 << '\n';
        else if (transitions == 1)
            cout << 2 << '\n';
        else
            cout << 1 << '\n';
    }

    return 0;
}