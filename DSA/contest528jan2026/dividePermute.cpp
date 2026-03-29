#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n + 1);
        vector<int> used(n + 1, 0);

        arr[n] = 1;
        used[1] = 1;

        for (int i = n - 1; i >= 1; i--) {
            int x = arr[i + 1] + i;
            int y = arr[i + 1] - i;

            if (x >= 1 && x <= n && !used[x]) {
                arr[i] = x;
                used[x] = 1;
            } else {
                arr[i] = y;
                used[y] = 1;
            }
        }

        for (int i = 1; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
