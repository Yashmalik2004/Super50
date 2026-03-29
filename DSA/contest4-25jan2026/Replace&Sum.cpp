#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, q;
    cin >> n >> q;

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
      cin >> b[i];
    }

    long long maxf = 0;
    for (int i = n - 1; i >= 0; i--)
    {
      maxf = max(maxf, b[i]);
      a[i] = max(a[i], maxf);
    }

    vector<long long> pref(n + 1);
    pref[0] = 0;
    for (int i = 0; i < n; i++)
    {
      pref[i + 1] = pref[i] + a[i];
    }

    while (q--)
    {
      int l, r;
      cin >> l >> r;
      l--;
      r--;
      cout << pref[r + 1] - pref[l] << " ";
    }
    cout << "\n";
  }
  return 0;
}
