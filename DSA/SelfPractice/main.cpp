#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        vector<long long> arr(n);
        map<long long, long long> mp;

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i] - (i + 1)]++;
        }

        long long ans = 0;
        for (auto &x : mp)
        {
            long long z = x.second;
            ans += z * (z - 1) / 2;
        }

        cout << ans << '\n';
    }
}
