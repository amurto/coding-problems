#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll solve()
{
    int a, b, k;
    cin >> a >> b >> k;
    vector<pair<int, int>> c(k);
    for (int i = 0; i < k; i++)
        cin >> c[i].first;
    for (int i = 0; i < k; i++)
        cin >> c[i].second;
    sort(c.begin(), c.end());
    vector<int> pre(b+1);
    ll res = 0;
    int l = 0, r = 0;
    while (r < k)
    {
        int i = r;
        while (r < k && c[r].first == c[i].first)
        {
            res += i - pre[c[r].second];
            r++;
        }
        while (i < r)
        {
            pre[c[i].second]++;
            i++;
        }
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