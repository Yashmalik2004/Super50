#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<long long, int> index;
        long long prefix = 0;
        int ans = 0;

        index[0] = -1;

        for (int i = 0; i < arr.size(); i++) {
            prefix += arr[i];

            if (index.find(prefix - k) != index.end()) {
                ans = max(ans, i - index[prefix - k]);
            }

            if (index.find(prefix) == index.end()) {
                index[prefix] = i;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> arr = {1, -1, 5, 2, 3};
    int k = 10;

    Solution obj;
    int result = obj.longestSubarray(arr, k);

    cout << "Longest subarray length with sum " << k << " = " << result << endl;

    return 0;
}
