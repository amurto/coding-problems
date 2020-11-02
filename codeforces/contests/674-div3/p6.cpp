#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

char sub[3] = {'a', 'b', 'c'};
ll DP[200001][3][3], MOD = 1000000007, POW[200001];

ll ADD(ll x, ll y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

ll MUL(ll x, ll y)
{
    return (x * 1ll * y) % MOD;
}

// No of subsequences is 3^(q-k)
// Where q is total count of '?' and k is count of '?' in current subsequence
ll NOS(string &str, int n, int i, int j, int k, int &q)
{
    if (j > 2) 
        return POW[q - k];
    if (i > n)
        return 0;
    if (DP[i][j][k] == -1)
    {
        DP[i][j][k] = 0;
        if (str[i] == '?')
            DP[i][j][k] = ADD(DP[i][j][k], NOS(str, n, i + 1, j + 1, k + 1, q));
        else if (str[i] == sub[j])
            DP[i][j][k] = ADD(DP[i][j][k], NOS(str, n, i + 1, j + 1, k, q));
        DP[i][j][k] = ADD(DP[i][j][k], NOS(str, n, i + 1, j, k, q));
    }
    return DP[i][j][k];
}

int main()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    int q = 0;
    for (char c : str)
        if (c == '?')
            q++;
    POW[0]=1;
    for (int i = 1; i <= q; i++)
        POW[i] = MUL(3, POW[i - 1]);
    memset(DP, -1, sizeof(DP));
    cout << NOS(str, n - 1, 0, 0, 0, q) << endl;
    return 0;
}