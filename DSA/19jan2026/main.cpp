class Solution
{
public:
  vector<int> firstNegInt(vector<int> &arr, int k)
  {
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
      cin >> arr[i];
    }

    queue<int> q;
    int l = 0;

    for (int r = 0; r < n; r++)
    {
      if (arr[r] < 0)
      {
        q.push(r);
      }

      if (r - l + 1 == k)
      {
        while (!q.empty() && q.front() < l)
        {
          q.pop();
        }

        if (q.empty())
        {
          cout << 0 << " ";
        }
        else
        {
          cout << arr[q.front()] << " ";
        }

        l++;
      }
    }

    return 0;
  }
};