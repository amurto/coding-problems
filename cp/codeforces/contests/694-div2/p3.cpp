#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n, m;
    cin >> n >> m;
    ll cost = 0;
    vector<ll> K(n), C(m);
    for (int i = 0; i < n; i++)
    {
        cin >> K[i];
        K[i]--;
    }
    sort(K.begin(), K.end(), greater<ll>());
    for (int i = 0; i < m; i++)
        cin >> C[i];
    int cur = 0;
    for (int i = 0; i < n; i++)
    {
        if (cur < m && K[i] > cur)
            cost += C[cur++];
        else
            cost += C[K[i]];
    }
    return cost;
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