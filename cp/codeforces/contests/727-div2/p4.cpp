#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    auto cmp = [&](int &i1, int &i2)
    {
        return b[i1] < b[i2];
    };
    priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < n; i++)
        pq.push(i);
    vector<int> ids(n);
    iota(ids.begin(), ids.end(), 0);
    sort(ids.begin(), ids.end(), [&](int &i1, int &i2)
         { return b[i1] < b[i2]; });
    ll bt = 0, res = 0;
    for (int i : ids)
    {
        while (!pq.empty() && bt < b[i])
        {
            int cur = pq.top();
            pq.pop();
            ll mn = min(a[cur], b[i] - bt);
            a[cur] -= mn;
            bt += mn;
            res += 2 * mn;
            if (a[cur] > 0)
                pq.push(cur);
        }
        if (bt < b[i])
            res += 2 * a[i];
        else
            res += a[i];
        bt += a[i];
        a[i] = 0;
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