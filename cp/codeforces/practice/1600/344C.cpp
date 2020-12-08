// https://codeforces.com/contest/344/problem/C
// Rational Resistance

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve(ll a, ll b)
{
    if (a == 1 || b == 1 || a == b)
        return max(a, b);
    if (a < b)
        swap(a, b);
    return a / b + solve(a % b, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll a, b;
    cin >> a >> b;
    cout << solve(a, b) << "\n";
    return 0;
}