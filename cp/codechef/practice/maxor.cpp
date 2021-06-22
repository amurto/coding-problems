// https://www.codechef.com/LTIME50/problems/MAXOR
// Good Pairs

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int LGN = 20;

ll solve()
{
    int n;
    cin >> n;
    map<int, int> cnt;
    vector<int> arr(n);
    vector<ll> dp(1 << LGN);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[arr[i]]++;
        cnt[arr[i]]++;
    }
    // SOS dp
    for (int b = 0; b < LGN; b++)
        for (int mask = 0; mask < (1 << LGN); mask++)
            if ((mask >> b) & 1)
                dp[mask] += dp[mask ^ (1 << b)];
    ll res = 0;
    for (auto c : cnt)
        res += c.second * dp[c.first] - c.second * c.second + (c.second * (c.second - 1)) / 2;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}