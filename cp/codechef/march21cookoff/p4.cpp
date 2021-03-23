#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, b = 0, inv = 0;
    cin >> n;
    vector<int> arr(n), t, p, k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        b |= arr[i];
    }
    for (int i = 1; i < n; i++)
        if (arr[i - 1] > arr[i])
            inv++;
    if (inv > n / 2)
    {
        t.pb(4);
        k.pb(b);
        p.pb(1);
        for (int i = 0; i < n; i++)
            arr[i] ^= b;
    }
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            t.pb(2);
            k.pb(arr[i - 1] - arr[i]);
            p.pb(i + 1);
        }
    }
    int x = t.size();
    cout << x << "\n";
    for (int i = 0; i < x; i++)
        cout << t[i] << " " << p[i] << " " << k[i] << "\n";
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