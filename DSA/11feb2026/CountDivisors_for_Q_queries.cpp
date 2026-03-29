#include<bits/stdc++.h>
using namespace std;

const int MX= 1e7;
vector<int> spf(MX + 1);

int main(){
  for(int i=0;i<=MX;i++){
    spf[i]=i;
  }
  for(int i=2;i*i<MX;i++){
    if(spf[i]==i){
      for(int j=i*i;j<=MX;j+=i){
        if(spf[j]==j) spf[j]=i;
      }
    }
  }

  long long q;
  cin>>q;
  while(q--){
    long long ans=1;
    long long n;
    cin>>n;
    while(n>1){
      int p=spf[n];
      int c=0;

      while(n%p==0){
        n/=p;
        c++;
      }
      ans=ans*(c+1);
    }
    cout<<ans<<"\n";
    
  }
}
