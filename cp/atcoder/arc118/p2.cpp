#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    int k;
    ll n, m;
    cin >> k >> n >> m;
    vector<ll> a(k), b(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
        a[i] *= m;
    }
    ll c = 0;
    for (int i = 0; i < k; i++)
    {
        ll d = a[i] / n;
        b[i] = d * n;
        c += d;
    }
    vector<int> seq(k);
    iota(seq.begin(), seq.end(), 0);
    sort(seq.begin(), seq.end(), [&](int &i1, int &i2) {
        return a[i1] - b[i1] > a[i2] - b[i2];
    });
    for (int i = 0; c < m && i < k; i++)
    {
        b[seq[i]] += n;
        c++;
    }
    for (int i = 0; i < k; i++)
        cout << b[i] / n << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}