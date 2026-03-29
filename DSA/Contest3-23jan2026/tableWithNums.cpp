#include <bits/stdc++.h>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, h, l;
        cin >> n >> h >> l;

        int both = 0, row = 0, col = 0;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a <= h && a <= l) both++;
            else if (a <= h) row++;
            else if (a <= l) col++;
        }

        int ans = 0;

        int x = min(row, col);
        ans += x;
        row -= x;
        col -= x;

        int y = min(row, both);
        ans += y;
        row -= y;
        both -= y;

        y = min(col, both);
        ans += y;
        col -= y;
        both -= y;

        ans += both / 2;

        cout << ans << '\n';
    }
    return 0;
}
