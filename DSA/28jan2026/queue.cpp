#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  queue<string> q;
  q.push("1");
  vector<string> ans;
  for(int i=0;i<n;i++){
    string s=q.front();
    q.pop();
    ans.push_back(s);
    q.push(s+"0");
    q.push(s+"1");

  }
for(int i=0;i<ans.size();i++){
  cout<<ans[i]<<"\n";
}
  return 0;
}