#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    ll k, x;
    cin >> k >> x;
    ll req = x + 1, cur = 0, pre = 0, res = 0;
    int b = 0;
    bool f = false;
    while (cur < req)
    {
        ll add = pre;
        res |= (1ll << b);
        if (f || ((k >> b) & 1))
            add = (1ll << b);
        if (cur + add > req)
        {
            if (f || ((k >> b) & 1))
            {
                f = true;
                cur++;
            }
            pre = 0;
            for (int c = 0; c < b; c++)
                res &= ~(1ll << c);
            b = 0;
        }
        else
        {
            cur += add;
            pre += add;
            b++;
        }
    }
    return res - 1;
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