// https://practice.geeksforgeeks.org/problems/wildcard-pattern-matching/1
// Wildcard Pattern Matching

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

// Recursive approach with memo
// Gives TLE on Leetcode
// Time and Space O(m*n)
int DP[201][201];
int WPM(string &p, string &s, int m, int n)
{
    if (n < 0 && m < 0)
        return 1;
    if (n < 0)
    {
        for (int i = m; i >= 0; i--)
            if (p[i] != '*')
                return 0;
        return 1;
    }
    if (m < 0 || n < 0)
        return 0;
    if (DP[m][n] < 0)
    {
        if (p[m] == '*')
            DP[m][n] = WPM(p, s, m, n - 1) || WPM(p, s, m - 1, n);
        else if (p[m] == '?')
            DP[m][n] = WPM(p, s, m - 1, n - 1);
        else if (p[m] == s[n])
            DP[m][n] = WPM(p, s, m - 1, n - 1);
        else
            DP[m][n] = 0;
    }
    return DP[m][n];
}

int wildCard(string str, string pattern)
{
    memset(DP, -1, sizeof(DP));
    return WPM(pattern, str, pattern.length() - 1, str.length() - 1);
}

// Optimized solution with two pointers
// Time O(m*n) and constant space
bool isMatch(string s, string p)
{
    int m = p.length(), n = s.length(), i = 0, j = 0, match = 0, star = -1;
    while (i < n)
    {
        if (j < m && (p[j] == '?' || s[i] == p[j]))
        {
            i++;
            j++;
        }
        else if (p[j] == '*')
        {
            star = j++;
            match = i;
        }
        else if (star != -1)
        {
            j = star + 1;
            i = ++match;
        }
        else
            return 0;
    }
    while (j < m && p[j] == '*')
        j++;
    return j == m;
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string pattern, str;
        cin >> str >> pattern;
        cout << isMatch(str, pattern) << endl;
    }
    return 0;
}