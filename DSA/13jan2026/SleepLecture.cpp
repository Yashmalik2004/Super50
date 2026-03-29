#include <iostream>
#include <vector>
#include <stdio.h>
#include <cmath>

using namespace std;

int main()
{
  int n;
  // cout << "enter no. of minute: ";
  cin >> n;
  int k;
  // cout << "enter awake time: ";
  cin >> k;
  vector<int> lecture(n);
  for (int i = 0; i < n; i++)
  {
    // cout << "lecture per minute: ";
    cin >> lecture[i];
  }
  vector<int> onoff(n);
  for (int i = 0; i < n; i++)
  {
    // cout << "onoff: ";
    cin >> onoff[i];
  }
  int basesum = 0;
  for (int i = 0; i < n; i++)
  {
    if (onoff[i] == 1)
    {
      basesum += lecture[i];
    }
  }
  vector<int> prefix(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    prefix[i] = prefix[i - 1];
    if (onoff[i - 1] == 0)
    {
      prefix[i] += lecture[i - 1];
    }
  }
  int best = 0;
  for (int i = 0; i + k <= n; i++)
  {
    best = max(best, prefix[i + k] - prefix[i]);
  }
  cout << basesum + best << endl;
}
