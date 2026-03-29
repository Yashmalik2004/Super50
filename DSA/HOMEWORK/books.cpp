#include<bits/stdc++.h>
using namespace std;

int books(int b,int t, int arr[]){
  long long sum=0;
  int left=0;
  int result=0;
  for(int right=0;right<b;right++){
    sum+=arr[right];

    while(sum>t){
      sum-=arr[left];
      left++;
    }
    result = max(result, right - left + 1);
  }
  return result;
}
int main(){
  int b,t;
  cin>>b>>t;
  vector<int> arr(b);
  for(int i=0;i<b;i++){
    cin>>arr[i];
  }
  cout<<books(b,t,arr.data());
  return 0;
}
