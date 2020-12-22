#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void factor(unordered_map<ll, ll> &PRIME, ll num)
{
    unordered_map<ll, ll> F;
    for (ll i = 2; i * i <= num; i++)
    {
        while (num % i == 0)
        {
            num /= i;
            F[i]++;
        }
    }
    if (num > 1)
        F[num]++;
    for (auto f : F)
        PRIME[f.first] = max(PRIME[f.first], f.second);
}

int solve()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> p(m);
    for (int i = 0; i < m; i++)
        cin >> p[i];
    if (n == 1)
        return 0;
    // lcm = product of (prime factor ^ maximum times it divides any arr[i])
    unordered_map<ll, ll> PRIME;
    for (ll num : p)
        factor(PRIME, num);

    ll lcm = 1;
    for (auto p : PRIME)
    {
        ll d = p.first, times = p.second;
        while (times-- > 0)
        {
            lcm *= p.first;
        }
    }
    if (n == lcm)
        return 0;
    if (n > lcm)
        return n - lcm;
    return n - 1;
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