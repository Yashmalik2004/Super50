#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n), nse(n), pse(n);
    stack<int> st;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        pse[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        int w = nse[i] - pse[i] - 1;
        x = max(x, arr[i] * w);
    }
    cout << x;
}
