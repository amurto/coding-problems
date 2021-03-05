// https://codeforces.com/contest/900/problem/D
// Unusual Sequences

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int MOD = 1e9 + 7;

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

void fac(vector<int> &st, int y)
{
    for (int i = 2; i * i <= y; i++)
    {
        if (y % i == 0)
        {
            while (y % i == 0)
                y /= i;
            st.pb(i);
        }
    }
    if (y > 1)
        st.pb(y);
}

int dfs(vector<int> &st, int y, int d, int p, int cur)
{
    if (cur == st.size())
        return (p & 1) ? -power(2, y / d - 1, MOD) : power(2, y / d - 1, MOD);
    return add(dfs(st, y, d, p, cur + 1), dfs(st, y, d * st[cur], p + 1, cur + 1));
}

int solve()
{
    int x, y;
    cin >> x >> y;
    if (x > y || y % x > 0)
        return 0;
    y /= x;
    vector<int> st;
    fac(st, y);
    return dfs(st, y, 1, 0, 0);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}