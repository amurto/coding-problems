#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    ll A, B;
    cin >> A >> B >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    for (int i = 0; i < n; i++)
    {
        ll d = b[i] / A;
        if (b[i] % A == 0)
            d--;
        B -= (a[i] * d);
        if (d > 0)
            b[i] %= (A * d);
        if (b[i] > 0)
            pq.push(a[i]);
    }
    while (B > 0 && !pq.empty())
    {
        B -= pq.top();
        pq.pop();
    }
    return pq.empty();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}