#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;

  while (t--)
  {
    int n;
    cin >> n;

    map<long long, long long> mp;
    for (int i = 1; i <= n; i++)
    {
      long long x;
      cin >> x;
      mp[x - i]++;
    }

    long long ans = 0;
    for (auto &p : mp)
    {
      long long x = p.second;
      ans += x * (x - 1) / 2;
    }

    cout << ans << '\n';
  }

  return 0;
}
