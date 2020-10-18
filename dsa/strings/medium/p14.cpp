// Longest Common Substring
// https://practice.geeksforgeeks.org/problems/longest-common-substring/0

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[101][101];

int calculateSubstring(string str1, string str2, int m, int n, int i, int j)
{
    if (i == m || j == n)
        return 0;
    if (DP[i][j] == -1)
        DP[i][j] = (str1[i] == str2[j]) ? 1 + calculateSubstring(str1, str2, m, n, i + 1, j + 1) : 0;
    return DP[i][j];
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int m, n, MAX = 0;
        string str1, str2;
        memset(DP, -1, sizeof(DP));
        cin >> m >> n >> str1 >> str2;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                MAX = max(MAX, calculateSubstring(str1, str2, m, n, i, j));

        cout << MAX << endl;
    }
    return 0;
}