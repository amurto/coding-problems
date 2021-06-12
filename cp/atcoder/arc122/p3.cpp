#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    ll x = 1, y = 0;
    for (int i = 0; i < 30; i++)
    {
        if (x < y)
            x += y;
        else
            y += x;
        cout << x << " " << y << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}