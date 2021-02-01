#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pii;
#define pb push_back

void solve()
{
    int n, op = 0;
    cin >> n;
    ll sum = 0;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    for (int i = 1; i < n; i++)
        pq.push({arr[i], i});
    ll cur = arr[0];
    vector<ll> p, q, res;
    while (op <= 2 * n && !pq.empty() && cur < sum)
    {
        pii f = pq.top();
        pq.pop();
        ll c = 0;
        if (cur < f.first)
            c = cur;
        else
            c = f.first;
        cur += c;
        f.first -= c;
        q.pb(1);
        p.pb(f.second + 1);
        res.pb(c);
        if (f.first > 0)
            pq.push(f);
    }
    if (op > 2 * n)
    {
        cout << "-1\n";
        return;
    }
    cout << res.size() << "\n";
    for (int i = 0; i < res.size(); i++)
        cout << p[i] << " " << q[i] << " " << res[i] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}