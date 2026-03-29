
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int L, R;
  cin >> L >> R;

  int r = sqrt(R);

  vector<int> primes(r + 1, 0);
  vector<int> ans;

  primes[0] = primes[1] = 1;

  for (int i = 2; i * i <= r; i++)
  {
    for (int j = i * i; j <= r; j += i)
    {
      primes[j] = 1;
    }
  }
  for (int i = 0; i <= r; i++)
  {
    if (primes[i] == 0)
      ans.push_back(i);
  }

  vector<int> final(R - L + 1, 0);
  for (auto x : ans)
  {
    int start = ((L + x - 1) / x) * x;
    start = max(start, x * x);

    for (int j = start; j <= R; j += x)
    {
      final[j - L] = 1;
    }
  }
  for (int i = 0; i < final.size(); i++)
  {
    if (final[i] == 0)
      cout << i + L << "\n";
  }
  return 0;
}