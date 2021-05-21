#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int n;
    cin >> n;
    ll res = 0;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    map<int, ll> cnt;
    for (int i = 1; i <= n; i++)
    {
        res += cnt[arr[i]] * (n - i + 1);
        cnt[arr[i]] += i;
    }
    return res;
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