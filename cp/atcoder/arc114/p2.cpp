#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 998244353;

int add(int x, int y)
{
    x += y;
    while (x >= MOD)
        x -= MOD;
    while (x < 0)
        x += MOD;
    return x;
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

int dfs(vector<int> &arr, vector<int> &c, int t, int cur, int &cnt)
{
    if (c[cur] > 0 && c[cur] < t)
        return c[cur];
    if (c[cur] == t)
    {
        cnt++;
        return t;
    }
    c[cur] = t;
    c[cur] = dfs(arr, c, t, arr[cur], cnt);
    return c[cur];
}

int solve()
{
    int n, cnt = 0;
    cin >> n;
    vector<int> arr(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    for (int i = 1; i <= n; i++)
        if (!c[i])
            dfs(arr, c, i, i, cnt);
    return add(power(2, cnt, MOD), -1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}