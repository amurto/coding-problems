// https://codeforces.com/contest/493/problem/C
// Vasya and Basketball

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    ll n, m, d, adx, bdx;
    cin >> n;
    vector<ll> A(n);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cin >> m;
    vector<ll> B(m);
    for (int i = 0; i < m; i++)
        cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    ll sca = 3 * n, diff = 3 * n - 3 * m;
    if (2 * n - 2 * m > diff)
    {
        diff = 2 * n - 2 * m;
        sca = 2 * n;
    }
    for (ll a : A)
    {
        adx = upper_bound(A.begin(), A.end(), a - 1) - A.begin();
        bdx = upper_bound(B.begin(), B.end(), a - 1) - B.begin();
        ll sc1 = 2 * adx + 3 * (n - adx), sc2 = 2 * bdx + 3 * (m - bdx);
        if ((sc1 - sc2 > diff) || (sc1 - sc2 == diff && sc1 > sca))
        {
            diff = sc1 - sc2;
            sca = sc1;
        }
    }
    cout << sca << ":" << sca - diff << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}