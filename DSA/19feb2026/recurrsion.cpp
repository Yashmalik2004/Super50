#include <bits/stdc++.h>
using namespace std;

void subs(vector<int>& nums,int idx,int cnt, int arr[], vector<vector<int>>ans){

        if(idx==nums.size()){
            vector<int> v;
            for(int i=0;i<cnt;i++){
                v.push_back(arr[i]);
            }
            ans.push_back(v);
            return ;
        }
        arr[cnt]=nums[idx];
        subs(nums,idx+1,cnt+1,arr,ans);
        arr[cnt+1]=nums[idx];
        subs(nums,idx+1,cnt+2,arr,ans);
        subs(nums,idx+1,cnt,arr,ans);

         
        
}
int main(){
  int n;
  cin>>n;
  vector<int> nums(n);
  for(int i=0;i<n;i++){
    cin>>nums[i];
  }
  vector<vector<int>> ans;
  int arr[20];

  subs(nums,0,0,arr,ans);


}