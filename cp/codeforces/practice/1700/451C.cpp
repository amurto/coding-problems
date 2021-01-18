// https://codeforces.com/contest/451/problem/C
// Predict Outcome of the Game

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int di[4] = {1, 1, -1, -1}, dj[4] = {1, -1, 1, -1};

bool op(ll n, ll k, ll d1, ll d2)
{

    ll tmp = k - d1 - d2;
    if (tmp < 0 || tmp % 3 > 0)
        return false;
    ll d = tmp / 3, req = n / 3;
    vector<ll> seq = {d + d1, d, d + d2};
    for (ll num : seq)
        if (num < 0 || num > req)
            return false;
    return true;
}

bool solve()
{
    ll n, k, d1, d2;
    cin >> n >> k >> d1 >> d2;
    if (n % 3 != 0)
        return false;
    for (int i = 0; i < 4; i++)
        if (op(n, k, di[i] * d1, dj[i] * d2))
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "yes\n" : cout << "no\n";
    return 0;
}