#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<ll> dp(50, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            dp[j] += (arr[i] & 1);
            arr[i] >>= 1;
        }
    }
    ll num = 0, mul = 1;
    for (int i = 0; i < 50; i++)
    {
        if (dp[i] & 1)
            num += mul;
        mul <<= 1;
    }
    return num;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}