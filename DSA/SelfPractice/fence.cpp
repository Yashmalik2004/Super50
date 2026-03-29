#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  long long arr[n];
  int k;
  cin>>k;
  vector<long long> p(n);
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  p[0]=arr[0];
  for(int i=1;i<n;i++){
    p[i]=p[i-1]+arr[i];
  }

  int minh=p[k-1];
  int l=0;
  for(int i=k;i<n;i++){
    int currsum=p[i]-p[i-k];
    if(currsum<minh){
      minh=currsum;
      l=i-k+1;
    }

  }
  cout<<l+1;
}