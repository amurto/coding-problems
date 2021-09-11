#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    ll res = 0;
    vector<pii> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end());
    map<pii, ll> dp;
    for (int idx = 0; idx < n;)
    {
        int r = idx;
        while (r < n && arr[idx].first == arr[r].first)
            r++;
        for (int i = idx; i < r; i++)
            for (int j = idx; j < i; j++)
                res += dp[{arr[j].second, arr[i].second}];
        for (int i = idx; i < r; i++)
            for (int j = idx; j < i; j++)
                dp[{arr[j].second, arr[i].second}]++;
        idx = r;
    }
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