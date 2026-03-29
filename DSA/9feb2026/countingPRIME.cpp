#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;

        vector<int> v(n + 1, 1);

        if(n >= 0) v[0] = 0;
        if(n >= 1) v[1] = 0;

        for(int i = 2; i * i <= n; i++){
            if(v[i]){
                for(int j = i * i; j <= n; j += i){
                    v[j] = 0;
                }
            }
        }

        int p = 0;
        for(int i = 0; i <= n; i++){
            p += v[i];
        }

        cout << p << endl;
    }
    return 0;
}
