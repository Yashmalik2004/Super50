#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
  int minn=min(a,b);
  int maxx=max(a,b);

  if(minn==0) return maxx;

  while(maxx%minn!=0){
    int t=minn;
    minn=maxx%minn;
    maxx=t;
  }
  return minn;
}
int lcm(int a,int b){
  return (a*b)/gcd(a,b);
}

int main(){
  int n;
  cin>>n;
  int a,b;
  cin>>a>>b;
  cout<<(n/a) + (n/b) - (n/lcm(a,b));
  return 0;
  
}