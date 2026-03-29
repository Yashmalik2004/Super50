#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    map<long long, long long> freq;
    long long prefix = 0;
    long long ans = 0;

    freq[0] = 1;  

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        ans += freq[prefix - k];
        freq[prefix]++;
    }

    cout << ans;
    return 0;
}
