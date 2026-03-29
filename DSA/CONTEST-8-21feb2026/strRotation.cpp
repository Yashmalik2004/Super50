// #include <bits/stdc++.h>
// using namespace std;

// bool hasDuplicates(string s)
// {
//   for (int i = 0; i < s.size(); i++)
//   {
//     if (s[i] == s[i - 1])
//       return false;
//   }
//   return true;
// }

// int main()
// {
//   int t;
//   cin >> t;
//   while (t--)
//   {
//     int n;
//     cin >> n;
//     string str;
//     cin >> str;

//     map<char, int> mp;
//     if (hasDuplicates(str)){
//       return n;
//     }
//     for(char c: str){
//       mp[c]++;
//     }
//     for(int i=0;i<str.size();i++){
//       char f=str[i];
//       char l=str[(i-1+n)%n];

//       if(f==l){
//         cout<<mp.size()<<endl;
//         return 0;
//       }
//     }
//     cout<<n<<endl;
//   }
//   return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{

  int t;
  cin>>t;

  while (t--)
  {
    int n;
    cin >> n;
    string str;
    cin >> str;

    int max_blocks = 0;
    for (int i = 0; i < n; i++)
    {
      int current_blocks = 1;
      for (int j = 0; j < n - 1; j++)
      {
        int curr = (i + j) % n;
        int next = (i + j + 1) % n;

        if (str[curr] != str[next])
        {
          current_blocks++;
        }
      }

      if (current_blocks > max_blocks)
      {
        max_blocks = current_blocks;
      }
    }

    cout << max_blocks << "\n";
  }

  return 0;
}