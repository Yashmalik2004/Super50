#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    int mini=min(a,b);
    int maxi=max(a,b);
    
    if(mini==0){
        return maxi;
    }
    while(maxi%mini!=0){
        int temp=mini;
        mini=maxi%mini;
        maxi=temp;
    }
    return mini;
}
int lcm(int a,int b){
    return (a*b)/gcd(a,b);
}
int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    
    for(int i=0;i<n;i++){
    cin>>v[i];
    }
    int LCM=v[0];
    
    for(int i=1;i<n;i++){
        LCM=lcm(LCM,v[i]);
    }
    cout<<LCM;

    return 0;
};