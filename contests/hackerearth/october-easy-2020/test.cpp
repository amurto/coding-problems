#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll bt(ll n, ll c, ll &cnt)
{
    if (n == 0)
    {
        if (c % 11 == 0)
        {
            cnt++;
            // cout << c << "\n";
        }
        return;
    }
    for (int i = 1; i <= 6; i++)
        bt(n - 1, c * 10 + i, cnt);
}
int main()
{
    for (int i=1; i<=7; i++) {
        ll cnt = 0;
        bt(i, 0, cnt);
        cout << i << " " << cnt << "\n";
    }
    return 0;
}