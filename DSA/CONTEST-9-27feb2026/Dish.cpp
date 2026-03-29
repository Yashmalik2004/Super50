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

    vector<int> dishes(n);
    int mx = INT_MIN;

    for (int i = 0; i < n; i++)
    {
      cin >> dishes[i];
      mx = max(mx, dishes[i]);
    }

    int c = 0;
    for (auto x : dishes)
    {
      if (x == mx)
        c++;
    }

    cout << c << '\n';
  }

  return 0;
}