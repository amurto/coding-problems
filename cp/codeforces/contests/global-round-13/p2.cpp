#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    ll u, v, cost = 2e9 + 5;
    cin >> n >> u >> v;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 1; i < n; i++)
        if (abs(arr[i] - arr[i - 1]) > 1)
            return 0;
    for (int i = 1; i < n; i++)
    {
        if (abs(arr[i] - arr[i - 1]) == 1)
            cost = min({cost, u, v});
        else
            cost = min({cost, u + v, 2 * v});
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
