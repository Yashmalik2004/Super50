/**
#include<bits/stdc++.h>
using namespace std;

int main(){
  map<string, int> marks;
  marks["sneha"]=85;
  marks["rakesh"]=90;
  marks["yash"]=100;
  for(auto i:marks){
    cout<<i.first<<" "<<i.second<<"\n";
  }
}
**/
// array a=[5,7,6,2,5,7,5]

#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cout<<"Enter size of array: ";
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++){
    cout<<"enter eles: ";
    cin>>a[i];
  }
  map<int,int> freq;
  for(int i=0;i<n;i++){
    freq[a[i]]++;
  }
  int maxf=0;
  for(auto i:freq){
    maxf=max(maxf,i.second);
  }
  for(auto i:freq){
    if(i.second==maxf){
      cout<<i.first;
    }
  }
}
