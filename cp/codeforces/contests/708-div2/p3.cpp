#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    ll n, k, cnt = 0;
    cin >> n >> k;
    if (k > 3)
    {
        cnt += k - 3;
        k = 3;
        n -= cnt;
    }
    while (cnt > 0)
    {
        cout << "1 ";
        cnt--;
    }
    ll x = 0, y = 0, z = 0;
    if (n & 1)
    {
        x = n / 2;
        y = n / 2;
        z = 1;
    }
    else
    {
        ll h = n / 4;
        if ((n / 2) & 1)
        {
            x = 2;
            n -= 2;
            y = z = n / 2;
        }
        else
        {
            x = n / 2;
            y = z = h;
        }
    }
    cout << x << " ";
    cout << y << " ";
    cout << z << "\n";
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