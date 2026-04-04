#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> arr;

        int l = 1, r = 3*n;

        while (arr.size() < 3*n) {
            arr.push_back(l);       
            arr.push_back(r-1);     
            arr.push_back(r);       

            l++;
            r -= 2;
        }

        for (int x : arr) cout << x << " ";
        cout << '\n';
    }

    return 0;
}