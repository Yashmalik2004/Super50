#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin >> s;

  long long n = s.size();

  vector<int> suffA(n, 0);
  vector<int> suffB(n, 0);
  vector<int> suffC(n, 0);

  for (int i = 1; i < n; i++)
  {
    if (s[i - 1] == 'A')
    {
      suffA[i]++;
    }
    suffA[i + 1] += suffA[i];
    if (s[i - 1] == 'B')
    {
      suffB[i]++;
    }
    suffB[i + 1] += suffB[i];
    if (s[i - 1] == 'C')
    {
      suffC[i]++;
    }
    suffC[i + 1] += suffC[i];
  }
  for (int i = 0; i < n; i++)
  {
    cout << suffA[i] << " ";
  }
  cout<<endl;
  for (int i = 0; i < n; i++)
  {
    cout << suffB[i] << " ";
  }
  cout<<endl;
  for (int i = 0; i < n; i++)
  {
    cout << suffC[i] << " ";
  }
  cout<<endl;
  return 0;
}