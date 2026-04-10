// #include<bits/stdc++.h>
// using namespace std;

// int main(){
//   int n;
//   cin>>n;
//   int msbPos=0;
//   while(n>1){
//     n=n>>1;
//     msbPos++;
//   }
//   cout<<msbPos<<endl;
//   return 0;
// }



#include <bits/stdc++.h>
using namespace std;

int main() {
    int left, right;
    cin >> left >> right;

    int msbL = 0, msbR = 0;

    int temp = left;
    while (temp > 1) {
        temp >>= 1;
        msbL++;
    }

    temp = right;
    while (temp > 1) {
        temp >>= 1;
        msbR++;
    }

    if (msbL != msbR) {
        cout << 0;
    } else {
        int ans = 1 << msbL;
        cout << ans;
    }

    return 0;
}