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
    vector<int> p(n);
    for (int i = 0; i < n; i++)
      cin >> p[i];

    for (int i = 0; i < n; i++)
    {
      int maxf = p[i], y = i;
      for (int j = i + 1; j < n; j++)
      {
        if (p[j] > maxf)
        {
          maxf = p[j];
          y = j;
        }
      }
      if (maxf > p[i])
      {
        reverse(p.begin() + i, p.begin() + y + 1);
        break;
      }
    }

    for (int x : p){
      cout << x << " ";
    }
    cout << "\n";
  }

  return 0;
}
