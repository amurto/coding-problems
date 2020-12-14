// https://codeforces.com/contest/405/problem/C
// Unusual Product

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q, type, x;
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n)), P(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];
    vector<int> rf(n), cf(n);
    int dp[n][n][2][2], sum = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][i][0][0] = dp[i][i][0][1] = dp[i][i][1][0] = dp[i][i][1][1] = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][i][0][0] += (A[i][j] * A[j][i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][i][0][1] += (A[i][j] * (A[j][i] ^ 1));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][i][1][0] += ((A[i][j] ^ 1) * A[j][i]);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][i][1][1] += ((A[i][j] ^ 1) * (A[j][i] ^ 1));
        P[i][i] = dp[i][i][0][0];
        sum += P[i][i];
    }
    vector<int> res;
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> type;
        if (type == 1 || type == 2)
        {
            cin >> x;
            x--;
            if (type == 1)
                rf[x] = (rf[x] + 1) % 2;
            else
                cf[x] = (cf[x] + 1) % 2;
            sum -= P[x][x];
            P[x][x] = dp[x][x][rf[x]][cf[x]];
            sum += P[x][x];
        }
        else
        {
            cout << sum % 2;
        }
    }
    cout << "\n";
    return 0;
}