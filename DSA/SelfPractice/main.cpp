#include <bits/stdc++.h>
using namespace std;

int solve(int idx, vector<int>& arr, curr, ans) {

    // Base case
    if (idx == arr.size()) {
        //now manullay check sum of each subset and check if it is divisible by k or not
        then if it is, then add ++ to a counter
    }

    curr.push_back(arr[idx]);
    solve(idx + 1, arr, curr,ans);
    curr.pop_back();
    solve(idx + 1, arr, curr,ans);

}

int main() {

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    vector<int> curr;
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << countSubsets(0, arr, curr, ans);

    return 0;
}
    
    
}
