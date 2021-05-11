// https://codeforces.com/contest/1379/problem/C
// Choosing flowers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back

ll solve()
{
    ll n;
    int m;
    cin >> n >> m;
    vector<pii> arr(m);
    for (int i = 0; i < m; i++)
        cin >> arr[i].first >> arr[i].second;
    sort(arr.begin(), arr.end(), [&](pii &p1, pii &p2) {
        return p1.second < p2.second;
    });
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    ll sum = 0, res = 0;
    for (int i = 0; i < m; i++)
    {
        while (!pq.empty() && pq.top() <= arr[i].second)
        {
            sum -= pq.top();
            pq.pop();
        }
        int sz = pq.size();
        if (sz <= n - 1)
            res = max(res, sum + arr[i].first + (n - sz - 1) * arr[i].second);
        sum += arr[i].first;
        pq.push(arr[i].first);
    }
    sort(arr.rbegin(), arr.rend());
    sum = 0;
    for (int i = 0; i < min(n, 1ll * m); i++)
        sum += arr[i].first;
    return max(res, sum);
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