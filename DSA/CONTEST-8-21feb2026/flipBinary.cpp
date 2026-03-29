#include <iostream>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;
  while (t--){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int countOnes = 0;
    int countZeros = 0;
    for (int i = 0; i < n; i++){
      if (s[i] == '1')
        countOnes++;
      else
        countZeros++;
    }
    if (countOnes % 2 == 0){
      cout << countOnes << "\n";
      bool first = true;
      for (int i = 0; i < n; i++){
        if (s[i] == '1'){
          if (!first)
            cout << " ";
          cout << i + 1;
          first = false;
        }
      }
      cout << "\n";
    }
    else if (countZeros % 2 != 0){
      cout << countZeros << "\n";
      bool first = true;
      for (int i = 0; i < n; i++){
        if (s[i] == '0'){
          if (!first)
            cout << " ";
          cout << i + 1;
          first = false;
        }
      }
      cout << "\n";
    }
    else{
      cout << "-1\n";
    }
  }
  return 0;
}