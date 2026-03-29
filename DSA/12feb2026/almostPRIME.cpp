#include <bits/stdc++.h>
using namespace std;

const int MAXM = 1e6;
vector<long long> S(MAXM + 1, 0);
vector<long long> cnt(MAXM + 1, 0);

int main()
{
  long long t;
  cin >> t;

  for (int i = 2; i <= MAXM; i++)
  {
    if (S[i] == 0)
    {
      for (int j = i; j <= MAXM; j += i)
      {
        S[j]++;
      }
    }
  }

  for (int i = 1; i <= MAXM; i++)
  {
    cnt[i] = cnt[i - 1];
    if (S[i] == 2)
      cnt[i]++;
  }

  while (t--)
  {
    long long n;
    cin >> n;
    cout << cnt[n] << endl;
  }
  return 0;
}