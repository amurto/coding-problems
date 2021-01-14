// https://codeforces.com/contest/525/problem/C
// Ilya and Sticks

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<ll> L(n), side;
    for (int i = 0; i < n; i++)
        cin >> L[i];
    sort(L.rbegin(), L.rend());
    for (int i = 0; i < n - 1; i++)
    {
        if (L[i] == L[i + 1])
        {
            side.pb(L[i]);
            i++;
        }
        else if (L[i] == (L[i + 1] + 1))
        {
            side.pb(L[i + 1]);
            i++;
        }
    }
    if (side.empty())
        return 0;
    ll res = 0;
    for (int i = 0; i < side.size() - 1; i += 2)
        res += side[i] * side[i + 1];
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