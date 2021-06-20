#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    ll k, x, sz = 1;
    cin >> n >> k >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] > x)
        {
            pq.push(arr[i] - arr[i - 1]);
            sz++;
        }
    }
    while (k > 0 && !pq.empty())
    {
        ll cur = pq.top();
        ll req = (cur - 1) / x;
        if (req > k)
            k = 0;
        else
        {
            k -= req;
            sz--;
            pq.pop();
        }
    }
    return sz;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}