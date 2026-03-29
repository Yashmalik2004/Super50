#include <bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        long long x;
        cin >> x;

        int c = 0;

        for(int s = 1; s <= 90; s++){
            long long y = x + s;

            long long temp = y;
            int sum = 0;
            while(temp > 0){
                sum += temp % 10;
                temp /= 10;
            }

            if(sum == s){
                c++;
            }
        }

        cout << c << '\n';
    }

    return 0;
}