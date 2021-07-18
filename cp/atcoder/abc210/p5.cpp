#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

ll solve()
{
    int n, m;
    cin >> n >> m;
    ll res = 0;
    vector<pii> arr(m);
    for (int i = 0; i < m; i++)
        cin >> arr[i].second >> arr[i].first;
    sort(arr.begin(), arr.end());
    for (int i = 0; n > 1 && i < m; i++)
    {
        int g = __gcd(n, arr[i].second);
        if (g < n)
        {
            res += 1ll * (n - g) * arr[i].first;
            n = g;
        }
    }
    if (n > 1)
        return -1;
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