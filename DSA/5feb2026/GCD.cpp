#include<bits/stdc++.h>
using namespace std;

int main(){

  int a,b;
  cin>>a>>b;

  int maxt=max(a,b);
  int mint=min(a,b);

  while(maxt%mint!=0){
    int temp=mint;
    mint=maxt%mint;
    maxt=temp;
  }

  cout<<mint;
}