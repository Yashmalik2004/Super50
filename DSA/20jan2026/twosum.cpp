#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,t;
  cin>>n>>t;
  vector<int> arr(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  map<int,int> map;
  for(int i=0;i<n;i++){
    int x=t-arr[i];
    if(map.find(x)!=map.end()){
      return {map[x],i}
    }
    map[arr[i]]=i;
  }
  return {};
}