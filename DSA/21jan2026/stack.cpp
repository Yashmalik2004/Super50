#include <bits/stdc++.h>
using namespace std;

int main()
{
  stack<int> st;
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<int> ans(n, -1);
  // for (int i = n - 1; i >= 0; i--)
  // {
  //   while (!st.empty() && st.top() <= arr[i])
  //   {
  //     st.pop();
  //   }

  //   ans[i] = st.empty() ? -1 : st.top();
  //   st.push(arr[i]);
  // }

  // for(auto x:ans){
  //   cout<<x<<" ";
  // }

  for (int i = n - 1; i >= 0; i--)
  {
    while (!st.empty() && st.top() >= arr[i])
    {
      st.pop();
    }

    ans[i] = st.empty() ? -1 : st.top();
    st.push(arr[i]);
  }

  for(auto x:ans){
    cout<<x<<" ";   
  }
}