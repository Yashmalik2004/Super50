#include<bits/stdc++.h>
using namespace std;

int main(){

  long long t;
  cin>>t;
  long long result=0;
  // int opr=0;
  vector<long long> v(t,0);
  for(int i=1;i<=t;i++){
    // opr++;
    for(int j=i;j<=t;j+=i){
      v[j-1]++;
      // opr++;
    }
    result+=v[i-1];

  }
  cout<<result<<endl;     
  for(int i=0;i<t;i++){
    cout<<v[i]<<" ";
  }
  // cout<<"opr: "<<opr;

  return 0;
}