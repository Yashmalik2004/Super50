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

    for (int i = 2; i < n; i++)
    {
      while (n % i == 0)
      {
        cout << i << " ";
        n = n / i;
      }
    }
  }
  
  return 0;
}
