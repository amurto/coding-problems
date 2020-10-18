// https://practice.geeksforgeeks.org/problems/count-of-strings-that-can-be-formed-using-a-b-and-c-under-given-constraints/0
// Count of strings that can be formed using a, b and c under given constraints

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
int dp[1001][2][3];
int createString(int n, int b, int c)
{
    if (n <= 0 || (b <= 0 && c <= 0))
        return 1;
    if (dp[n][b][c])
        return dp[n][b][c];
    dp[n][b][c] += createString(n - 1, b, c);
    if (b > 0)
        dp[n][b][c] += createString(n - 1, b - 1, c);
    if (c > 0)
        dp[n][b][c] += createString(n - 1, b, c - 1);
    return dp[n][b][c];
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        cout << createString(n, 1, 2) << endl;
    }
    return 0;
}