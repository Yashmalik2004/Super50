/*given a string s, remove some char such that: no duplicates, and the new string is lexographically smaller. */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    map<char, int> last;
    for (int i = 0; i < s.size(); i++){
      last[s[i]] = i;
    }

    map<char, bool> used;
    stack<char> st;

    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];

        if (used[c])
            continue;

        while (!st.empty() &&
               c < st.top() &&
               last[st.top()] > i)
        {
            used[st.top()] = false;
            st.pop();
        }

        st.push(c);
        used[c] = true;
    }

    string ans;
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    cout << ans << endl;
}
