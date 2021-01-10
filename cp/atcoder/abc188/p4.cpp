#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    ll a, b, c, cost;
    cin >> n >> cost;
    vector<pair<ll, ll>> seq;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        seq.pb({a, c});
        seq.pb({b + 1, -c});
    }
    sort(seq.begin(), seq.end());
    ll res = 0, cur = 0, last = 0;
    for (int i = 0; i < seq.size(); i++)
    {
        res += (seq[i].first - last) * min(cost, cur);
        cur += seq[i].second;
        if (seq[i].first > last)
            last = seq[i].first;
    }
    cout << res << "\n";
    return 0;
}