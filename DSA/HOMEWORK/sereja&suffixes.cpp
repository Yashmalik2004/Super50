#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> queries(m);
    for (int i = 0; i < m; i++) {
        cin >> queries[i];
    }

    vector<int> dst(n);
    unordered_set<int> seen;
    for (int i = n - 1; i >= 0; i--) {
        if (seen.find(arr[i]) == seen.end()) {
            seen.insert(arr[i]);
            dst[i] = (i == n - 1 ? 1 : dst[i + 1] + 1);
        } else {
            dst[i] = (i == n - 1 ? 1 : dst[i + 1]);
        }
    }

    for (int i = 0; i < m; i++) {
        cout << dst[queries[i] - 1] << '\n';
    }

    return 0;
}
