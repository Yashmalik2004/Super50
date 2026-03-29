// max( p*arr[i] + q*arr[j] + r*arr[k]), where i < j < k

#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> v(n);
  for(int i=0;i<n;i++){
    cin>>v[i];
  }

  int p,q,r;
  cout<<"enter p: ";
  cin>>p;
  cout<<"enter q: ";
  cin>>q;
  cout<<"enter r: ";
  cin>>r;

  vector<int> prefix(n);
  vector<int> suffix(n);

  prefix[0]=p*v[0];
  for(int i=1;i<n;i++){
    prefix[i]=max(prefix[i-1],p*v[i]);
  }

  suffix[n-1]=r*v[n-1];
  for(int i=n-2;i>=0;i--){
    suffix[i]=max(suffix[i+1],r*v[i]);
  }
  
  int result = INT_MIN;

  for(int i=1;i<n-1;i++){
    int left= prefix[i-1];
    int mid= q*v[i];
    int right= suffix[i+1];

    result = max(result, left + mid + right);
  }
  cout<< result<< endl;
  return 0;
}