#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

ll solve()
{
    int n;
    ll c;
    cin >> n >> c;
    vector<ll> cnt(n + 1);
    vector<pii> arr(n);
    map<ll, ll> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
        if (arr[i].second - arr[i].first >= 2)
        {
            mp[arr[i].first + 1]++;
            mp[arr[i].second]--;
        }
    }
    ll v = 0, prev = 0;
    for (auto x : mp)
    {
        cnt[v] += x.first - prev;
        v += x.second;
        prev = x.first;
    }
    ll cur = n;
    for (int i = n; c > 0 && i > 0; i--)
    {
        // there are cnt[i] points overlapped by i intervals
        ll mn = min(c, cnt[i]);
        cur += 1ll * i * mn;
        c -= mn;
        cnt[v] -= mn;
    }
    return cur;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}