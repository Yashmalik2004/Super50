#include <bits/stdc++.h>
using namespace std;

long long maxPower(vector<int> &a, long long c, long long k)
{
  sort(a.begin(), a.end());

  for (int i = 0; i < a.size(); i++)
  {
    if (a[i] > c)
      break;

    long long use = min(k, c - a[i]);
    c += a[i] + use;
    k -= use;
  }

  return c;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    long long c, k;

    cin >> n >> c >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    cout << maxPower(a, c, k) << endl;
  }
}