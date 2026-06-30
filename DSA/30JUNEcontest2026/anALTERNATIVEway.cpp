#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        bool ok = true;
        bool seenOne = false;

        for (char c : s) {
            if (c == '1')
                seenOne = true;
            else if (seenOne) {
                ok = false;   // found a 0 after a 1
                break;
            }
        }

        cout << (ok ? "Bob" : "Alice") << '\n';
    }

    return 0;
}