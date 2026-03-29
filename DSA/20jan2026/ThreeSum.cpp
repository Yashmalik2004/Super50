#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<int, int> freq;
    for (int x : arr) {
        freq[x]++;
    }
    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n - 2; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        for (int j = i + 1; j < n - 1; j++) {
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;

            int k = -(arr[i] + arr[j]);

            if (k > arr[j] && freq[k] > 0) {
                ans.push_back({arr[i], arr[j], k});
            }

            else if (k == arr[j] && freq[k] >= 2) {
                ans.push_back({arr[i], arr[j], k});
            }
        }
    }

    for (auto &v : ans) {
        cout << v[0] << " " << v[1] << " " << v[2] << "\n";
    }

    return 0;
}
