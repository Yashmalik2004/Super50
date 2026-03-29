#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> cnt(n, 0);
    long long sum = 0;
    cnt[0] = 1; 

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        sum += x;
        long long mod = ((sum % n) + n) % n;
        cnt[mod]++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cnt[i] * (cnt[i] - 1) / 2;
    }

    cout << ans << endl;
    return 0;
}
