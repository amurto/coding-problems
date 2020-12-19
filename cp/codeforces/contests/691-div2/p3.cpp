#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<ll> A(n), B(m);
    for (int i = 0; i < n; i++)
        cin >> A[i];
    for (int i = 0; i < m; i++)
        cin >> B[i];

    ll g = 0;
    for (int i = 0; i < n; i++)
        g = __gcd(g, A[i]);
    ll num = g;
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

    for (int i = 0; i < m; i++)
    {
        for (auto x: F) {
            
        }
    }
    cout << g << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}