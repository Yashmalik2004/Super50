#include<bits/stdc++.h>
using namespace std;

int main(){
  int n=16;
  for(int i=0;i<32;i++){
    if(n&(1<<i)){
      cout<<i;
      break;
    }
    else continue;
  }
  return 0;
}