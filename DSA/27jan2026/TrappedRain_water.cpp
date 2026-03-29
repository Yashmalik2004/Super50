#include<bits/stdc++.h>
using namespace std;

int trap(vector<int> & heights){

  int n=heights.size();

  vector<int> prefix(n);
  vector<int> suffix(n);

  prefix[0]=heights[0];
  for(int i=1;i<n;i++){
    prefix[i]=max(prefix[i-1],heights[i]);
  }

  suffix[n-1]=heights[n-1];
  for(int i=n-2;i>=0;i--){
    suffix[i]=max(suffix[i+1],heights[i]);
  }

  int amount = 0;

  for(int i=0;i<n;i++){
    int left= prefix[i];
    int h= heights[i];
    int right= suffix[i];

    int decide_height = min(left,right);
    amount += (decide_height - h);
  }
  return amount;

}

int main(){
  int n;
  cin>>n;

  vector<int> heights(n);
  for(int i=0;i<n;i++){
    cin>>heights[i];
  }
  cout<< trap(heights);
}