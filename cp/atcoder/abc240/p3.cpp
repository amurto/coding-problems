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

bool solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    vector<bool> dp(x + 1);
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        vector<bool> tdp(x + 1);
        for (int j = 0; j <= x; j++)
        {
            if (dp[j])
            {
                if (j + a[i] <= x)
                    tdp[j + a[i]] = true;
                if (j + b[i] <= x)
                    tdp[j + b[i]] = true;
            }
        }
        swap(dp, tdp);
    }
    return dp[x];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}