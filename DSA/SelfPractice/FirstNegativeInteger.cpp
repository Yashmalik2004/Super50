#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> firstNegInt(vector<int> &arr, int k){
      int n=arr.size();
        deque<long long> dq;
        vector<long long> ans;
        for(int i=0;i+k-1<n;i++){
            if(arr[i]<dq.front()){
                dq.push_front(arr[i]);
            }
            if(dq.front()<0){
              ans.push_back(dq.front());
            }
            else{
              ans.push_back(0);
            }
            dq.pop_back();
        }
        for(auto i:ans){
          cout<<i<<" ";
        }
}
};
int main(){
    Solution obj;
    vector<int> arr={-8,2,3,-6,10};
    int k=2;
    obj.firstNegInt(arr,k);
    return 0;
}