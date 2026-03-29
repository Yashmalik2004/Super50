#include <bits/stdc++.h>
using namespace std;

vector<int> nums;
int cs(int idx, int ts)
{
  if (idx == nums.size())
  {
    return (ts == 0);
  }
  sort(nums.begin(),nums.end());
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
  cout << cs(0, 9);
  return 0;
}