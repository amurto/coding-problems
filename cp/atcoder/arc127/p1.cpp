#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int K = 16;
int st[K];
ll calc()
{
    ll num = 0;
    for (int i = 0; i < K; i++)
        num = num * 10 + st[i];
    return num;
}

ll dfs(int cur, ll ones, ll n)
{
    if (calc() > n)
        return 0;
    if (cur == K)
    {
        if (calc() <= n)
            return ones;
        return 0;
    }
    ll res = 0;
    for (int j = 0; j <= 9; j++)
    {
        if (j == 1)
        {
            st[cur] = 1;
            res += dfs(cur + 1, ones + 1, n);
            st[cur] = 0;
        }
        else
        {
            st[cur] = j;
            ll num = calc();
            if (num <= n)
            {
                for (int k = cur + 1; k < K; k++)
                    st[k] = 9;
                res += ones * (min(n, calc()) - num + 1);
                for (int k = cur + 1; k < K; k++)
                    st[k] = 0;
            }
            st[cur] = 0;
        }
    }
    return res;
}

ll solve()
{
    ll n, res = 0;
    cin >> n;
    for (int i = 0; i < K; i++)
        res += dfs(i, 0, n);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}