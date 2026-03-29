#include <bits/stdc++.h>
using namespace std;

int solveFor(char ch, const string& s, int k) {
    int l = 0, changes = 0, best = 0;

    for (int r = 0; r < s.size(); r++) {
        if (s[r] != ch) {
            changes++;
        }

        while (changes > k) {
            if (s[l] != ch) {
                changes--;
            }
            l++;
        }

        best = max(best, r - l + 1);
    }

    return best;
}

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    int ans = max(solveFor('a', s, k), solveFor('b', s, k));
    cout << ans << endl;

    return 0;
}
