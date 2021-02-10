// https://codeforces.com/problemset/problem/223/C
// Partial Sums

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 2005, MOD = 1e9 + 7;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
}

int mul(int x, int y)
{
    return (x * 1ll * y) % MOD;
}

// Binary Exponentiation O(logn)
// n^m mod p
int power(int n, int m, int p)
{
    int res = 1;
    while (m > 0)
    {
        if (m & 1)
            res = (res * 1ll * n) % p;
        n = (n * 1ll * n) % p;
        m /= 2;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<vector<int>> ncr(n + 5, vector<int>(n + 5));
    for (int i = 0; i < n + 5; i++)
        ncr[i][0] = 1;
    for (int j = 1; j < n + 5; j++)
        ncr[0][j] = mul(ncr[0][j - 1], mul(k - j + 1, power(j, MOD - 2, MOD)));
    for (int i = 1; i < n + 5; i++)
        for (int j = 1; j < n + 5; j++)
            ncr[i][j] = add(ncr[i - 1][j - 1], ncr[i - 1][j]);
    for (int i = 0; i < n; i++)
    {
        int res = arr[i];
        for (int j = 0; j < i; j++)
            res = add(res, mul(ncr[i - j - 1][i - j], arr[j]));
        cout << res << " ";
    }
    return 0;
}