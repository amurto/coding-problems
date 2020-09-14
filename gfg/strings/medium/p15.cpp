// https://practice.geeksforgeeks.org/problems/longest-repeating-and-non-overlapping-substring/0
// Longest repeating and non-overlapping substring

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[1001][1001];

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s;
        int n, MAX = 0, start = 0;
        cin >> n >> s;
        memset(DP, 0, sizeof(DP));
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (s[i - 1] == s[j - 1] && DP[i - 1][j - 1] < (j - i))
                {
                    DP[i][j] = 1 + DP[i - 1][j - 1];
                    if (DP[i][j] > MAX)
                    {
                        MAX = DP[i][j];
                        start = i;
                    }
                }
                else
                    DP[i][j] = 0;
            }
        }
        if (MAX == 0)
            cout << -1 << endl;
        else
            cout << s.substr(start - MAX, MAX) << endl;
    }
    return 0;
}