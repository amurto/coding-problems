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

    sort(A.begin(), A.end());
    ll g = 0;
    for (int i = 1; i < n; i++)
        g = __gcd(g, A[i] - A[i - 1]);
    for (ll b : B)
        cout << __gcd(A[0] + b, g) << " ";
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