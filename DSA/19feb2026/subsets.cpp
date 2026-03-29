// class Solution {
// public:
// void subs(vector<int>& nums,int idx,int cnt, int arr[], vector<vector<int>>ans){

//         if(idx==nums.size()){
//             vector<int> v;
//             for(int i=0;i<cnt;i++){
//                 v.push_back(arr[i]);
//             }
//             ans.push_back(v);
//             return ;
//         }
//         arr[cnt]=nums[idx];
//         subs(nums,idx+1,cnt+1,arr,ans);
//         subs(nums,idx+1,cnt,arr,ans);
// }
//     vector<vector<int>> subsets(vector<int>& nums) {
//       vector<vector<int>>ans;
//       int arr[20];

//     subs(nums, 0, 0, arr, ans);

//     return ans;
//     }
// };