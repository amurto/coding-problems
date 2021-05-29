#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
#define pb push_back

const ll inf = 1e18;
ll solve()
{
    int n;
    cin >> n;
    n *= 2;
    vector<pii> arr(n);
    vector<int> cnt(3);
    char ch;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> ch;
        if (ch == 'R')
            arr[i].second = 0;
        else if (ch == 'G')
            arr[i].second = 1;
        else
            arr[i].second = 2;
        cnt[arr[i].second]++;
    }
    if (cnt[0] % 2 == 0 && cnt[1] % 2 == 0)
        return 0;
    if (cnt[0] % 2 == 1)
    {
        map<int, int> mp;
        if (cnt[1] % 2 == 0)
        {
            mp[0] = 1;
            mp[1] = 0;
            mp[2] = 2;
            swap(cnt[0], cnt[1]);
        }
        else
        {
            mp[0] = 2;
            mp[1] = 1;
            mp[2] = 0;
            swap(cnt[0], cnt[2]);
        }
        for (int i = 0; i < n; i++)
            arr[i].second = mp[arr[i].second];
    }
    vector<pii> gb;
    ll mn = inf;
    for (int i = 0; i < n; i++)
        if (arr[i].second > 0)
            gb.pb(arr[i]);
    sort(gb.begin(), gb.end());
    for (int i = 1; i < gb.size(); i++)
        if (gb[i - 1].second != gb[i].second)
            mn = min(mn, abs(gb[i].first - gb[i - 1].first));
    if (cnt[0] == 0)
        return mn;
    vector<ll> r, g, b;
    for (int i = 0; i < gb.size(); i++)
        if (gb[i].second == 1)
            g.pb(gb[i].first);
        else
            b.pb(gb[i].first);
    for (int i = 0; i < n; i++)
        if (arr[i].second == 0)
            r.pb(arr[i].first);
    sort(r.begin(), r.end());
    int sz = r.size();
    vector<ll> mng(sz, inf), mnb(sz, inf);
    for (int i = 0; i < sz; i++)
    {
        int lb = lower_bound(g.begin(), g.end(), r[i]) - g.begin();
        if (lb < g.size())
            mng[i] = abs(r[i] - g[lb]);
        lb--;
        if (lb >= 0)
            mng[i] = min(mng[i], abs(r[i] - g[lb]));
        lb = lower_bound(b.begin(), b.end(), r[i]) - b.begin();
        if (lb < b.size())
            mnb[i] = abs(r[i] - b[lb]);
        lb--;
        if (lb >= 0)
            mnb[i] = min(mnb[i], abs(r[i] - b[lb]));
    }
    vector<ll> sufg(sz), sufb(sz);
    sufg[sz - 1] = mng[sz - 1];
    sufb[sz - 1] = mnb[sz - 1];
    for (int i = sz - 2; i >= 0; i--)
    {
        sufg[i] = min(mng[i], sufg[i + 1]);
        sufb[i] = min(mnb[i], sufb[i + 1]);
    }
    ll preg = inf, preb = inf, dis = inf;
    for (int i = 0; i < sz - 1; i++)
    {
        preg = min(preg, mng[i]);
        preb = min(preb, mnb[i]);
        dis = min(dis, min(preg + sufb[i + 1], preb + sufg[i + 1]));
    }
    return min(mn, dis);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}