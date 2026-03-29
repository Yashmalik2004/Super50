#include<bits/stdc++.h>
using namespace std;

long long pascal[61][61];

void findpascal(){
  pascal[0][0]=1;
  for(int i=1;i<=60;i++){
    for(int j=0;j<=i;j++){
      if(j==0 || j==i){
        pascal[i][j]=1;
      }
      else{
        pascal[i][j]=pascal[i-1][j-1] + pascal[i-1][j];
      }
    }
  }
};
int main(){
  findpascal();
  int n,r;
  cin>>n>>r;
  cout<<pascal[n][r]<<endl;
  return 0;
}