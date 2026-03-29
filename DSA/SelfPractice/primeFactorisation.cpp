#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n;
  cin>>n;
  int r=sqrt(n);

  vector<long long> primes(r+1,0);
  vector<int> ans;
  primes[0]=primes[1]=1;

  for(int i=2;i<=r;i++){
    if(primes[i]==0){
      for(int j=i*i;j<=r;j+=i) primes[j]=1;
    }
  }
  for(int i=2;i<=r;i++){
    if(primes[i]==0) ans.push_back(i);
  }
  vector<int> freq(r+2,0);
  for(int i=0;i<ans.size();i++){
    while(n%ans[i]==0){
      n=n/ans[i];
      freq[ans[i]]=1;
    }
  }
  vector<int> finalAns;
  for(int i=0;i<freq.size();i++){
    if(freq[i]==1){
      finalAns.push_back(i);
    }
  }
  if(n>1){
    finalAns.push_back(n);
  }
  for(auto x:finalAns){
    cout<<x<<" ";
  }
  return 0;
}