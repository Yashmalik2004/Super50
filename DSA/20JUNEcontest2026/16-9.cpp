#include<bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int X,Y;
  cin>>X>>Y;
  if(X%16==0 && Y%9==0)
    cout<<"YES";
  else
    cout<<"NO";

  return 0;
}