#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
int cs(int idx, int ts)
{
  if (ts == 0) return 1;
  if (ts < 0 || idx == nums.size()) return 0;

  return cs(idx,ts-nums[idx]) + cs(idx+1,ts);
}
int main()
{
  int n;
  cin >> n;
  nums.resize(n);
  for (int i = 0; i < n; i++)
  {
    cin >> nums[i];
  }
  cout << cs(0, 3);
  return 0;
}