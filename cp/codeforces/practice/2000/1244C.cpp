// https://codeforces.com/contest/1244/problem/C
// The Football Season

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    for (ll draws = 0; draws < w; draws++)
    {
        ll rem = p - draws * d;
        if (rem >= 0 && rem % w == 0 && draws + rem / w <= n)
        {
            cout << rem / w << " " << draws << " " << n - rem / w - draws << "\n";
            return;
        }
    }
    cout << "-1\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}