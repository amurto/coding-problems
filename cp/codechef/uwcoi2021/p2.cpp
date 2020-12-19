#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    ll mn = INT_MAX, b, res = 0;
    vector<ll> A(n);
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
        mn = min(mn, A[i]);
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b;
        if (b < mn)
            res += n;
    }
    cout << res << "\n";
    return 0;
}