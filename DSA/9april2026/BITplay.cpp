#include<bits/stdc++.h>
using namespace std;

int countBits(int x) {
    int count = 0;
    while (x) {
        x = x & (x - 1); 
        count++;
    }
    return count;
}

int main(){

  int t;
  cin>>t;
  while(t--){

    int n;
    cin>>n;
    int k;
    cin>>k;
    int ans;
    int i=(n%2==0) ? n-1:n-2;
    for(int x=i;x>=1;x-=2){
      if(countBits(x)==k){
        ans=x;
        break;
      }
    }
    if(ans) cout<<ans<<endl;
    else cout<<-1<<endl;
  }
  return 0;

}