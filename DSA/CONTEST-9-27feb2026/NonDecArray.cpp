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

    vector<int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];

    if (n < 2)
    {
      cout << 1 << "\n";
      continue;
    }

    bool nonDec = true;

    for (int i = 0; i < n - 1; i++)
    {
      if (a[i] > a[i + 1])
      {
        nonDec = false;
        break;
      }
    }

    if (nonDec)
      cout << n << "\n";
    else
      cout << 1 << "\n";
  }

  return 0;
}