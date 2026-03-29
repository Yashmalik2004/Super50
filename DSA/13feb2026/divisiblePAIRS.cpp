#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long t;
  cin >> t;
  while (t--)
  {

    long long n;
    cin >> n;
    vector<long long> v(n);
    map<long long, long long> mp;
    int k=4;

    for (int i = 0; i < n; i++)
    {
      cin >> v[i];
      mp[v[i] % k]++;
    }
    long long c = 0;
    c += (mp[0] * (mp[0] - 1)) / 2;

    for (int i = 1; i <= k / 2; i++)
    {
      if (i == k - i)
      {
        c += (mp[i] * (mp[i] - 1)) / 2;
      }
      else
      {
        c += mp[i] * mp[k - i];
      }
    }
    cout << c<< endl;
  }

  return 0;
}