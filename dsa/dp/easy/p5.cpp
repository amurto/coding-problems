// https://practice.geeksforgeeks.org/problems/find-number-of-times-a-string-occurs-as-a-subsequence3020/1
// String Subsequence

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int DP[500][500];

int CW(string s1, string s2, int m, int n)
{
    if (n < 0)
        return 1;
    if (m < 0)
        return 0;
    if (DP[m][n] < 0)
        if (s1[m] == s2[n])
            DP[m][n] = CW(s1, s2, m - 1, n) + CW(s1, s2, m - 1, n - 1);
        else
            DP[m][n] = CW(s1, s2, m - 1, n);
    return DP[m][n];
}

int countWays(string s1, string s2)
{
    memset(DP, -1, sizeof(DP));
    return CW(s1, s2, s1.length() - 1, s2.length() - 1);
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << countWays(s1, s2) << endl;
    }
    return 0;
}