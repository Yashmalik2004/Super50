#include<bits/stdc++.h>
using namespace std;

int main(){
  long long n = 1e15;;
  int c=0;
  // for(int i=0;i<32;i++){
  //   if(n&(1<<i)){
  //     cout<<i;
  //     break;
  //   }
  //   else continue;
  // }
  while(n){
    n = n & (n-1);
    c++;
  }
  cout<<c;
  return 0;
}