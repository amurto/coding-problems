#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1), c(n + 1), freqC(n + 1), freqB(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        freqC[c[i]]++;
    }
    for (int i = 1; i <= n; i++)
        freqB[b[i]] += freqC[i];
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res += freqB[a[i]];
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