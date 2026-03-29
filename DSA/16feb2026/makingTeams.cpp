#include <iostream>
using namespace std;

long long pascal[61][61];

void findpascal()
{
  pascal[0][0] = 1;

  for (int i = 1; i <= 60; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      if (j == 0 || j == i)
        pascal[i][j] = 1;
      else
        pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];
    }
  }
}

int main()
{
  findpascal();
  int t;
  cin >> t;
  while (t--)
  {
    int n, m, x;
    cin >> n >> m >> x;

    long long result = pascal[n + m][x] - ((pascal[n][0] * pascal[m][x]) + (pascal[n][1] * pascal[m][x - 1]) + (pascal[n][2] * pascal[m][x - 2]) + (pascal[n][3] * pascal[m][x - 3]) + (pascal[n][x] * pascal[m][0]));

    cout << result;
  }
  return 0;
}
