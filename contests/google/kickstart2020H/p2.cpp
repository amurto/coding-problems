#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll dp[20][2][20];

vector<int> num;
ll bn(int cur, int f, int start)
{
    if (cur == num.size())
    {
        if (start == 1)
            return 0;
        return 1;
    }
    if (dp[cur][f][start] == -1)
    {
        int limit = 9, par = start % 2;
        ll res = 0;
        if (f)
            limit = num[cur];

        if (start == 1)
            res += bn(cur + 1, false, start);
        else if (par == 0)
        {
            bool nf = false;
            if (f && num[cur] == 0)
                nf = true;
            res = bn(cur + 1, nf, start + 1);
        }

        for (int i = 1; i <= limit; i++)
        {
            if (i % 2 == par)
            {
                bool nf = false;
                if (f && i == num[cur])
                    nf = true;
                res += bn(cur + 1, nf, start + 1);
            }
        }
        dp[cur][f][start] = res;
    }
    return dp[cur][f][start];
}

ll solve(ll x)
{
    num.clear();
    while (x > 0)
    {
        num.pb(x % 10);
        x /= 10;
    }
    reverse(num.begin(), num.end());
    memset(dp, -1, sizeof(dp));
    return bn(0, true, 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        ll L, R;
        cin >> L >> R;
        ll res = solve(R) - solve(L - 1);
        cout << "Case #" << i << ": " << res << "\n";
    }
    return 0;
}