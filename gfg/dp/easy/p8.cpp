// https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence/0
// Longest Repeating Subsequence

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[1001][1001];

int LRS(string &str, int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    if (DP[i][j] < 0)
        if (str[i] == str[j] && i != j)
            DP[i][j] = 1 + LRS(str, i - 1, j - 1);
        else
            DP[i][j] = max(LRS(str, i - 1, j), LRS(str, i, j - 1));
    return DP[i][j];
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        string str;
        cin >> n >> str;
        memset(DP, -1, sizeof(DP));
        cout << LRS(str, n - 1, n - 1) << endl;
    }
    return 0;
}