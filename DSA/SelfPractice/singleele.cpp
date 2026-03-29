#include <bits/stdc++.h>
using namespace std;
int search(vector<int> &arr){
     int l=0,r=arr.size()-1;
     while(l<r){
          int m=l+(r-l)/2;
          if(m>0 && m<arr.size()-1 && arr[m]!=arr[m-1] && arr[m]!=arr[m+1]){ 
               return arr[m];
          }
          if(m>0 && arr[m]==arr[m-1]){
               if(m%2!=0) l=m+1;
               else r=m-1;
          }
          else if(m<arr.size()-1 && arr[m]==arr[m+1]){
               if(m%2!=0){
                    r=m-1;
               }
               else l=m+1;
          }
          else return arr[m];
          
     }
     return 0;
     
}
int main() {
    // your code goes here
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)cin>>arr[i];
    int ans=search(arr);
    cout<<ans;
    
     
    return 0;
}