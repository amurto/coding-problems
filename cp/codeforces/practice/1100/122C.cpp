// https://codeforces.com/contest/122/problem/C
// Lucky Sum

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const ll inf = 1e10;
vector<ll> lucky;
void dfs(ll cur)
{
    if (cur >= inf)
        return;
    lucky.pb(cur);
    dfs(cur * 10 + 4);
    dfs(cur * 10 + 7);
}

ll solve()
{
    ll L, R, res = 0;
    cin >> L >> R;
    int idx = lower_bound(lucky.begin(), lucky.end(), L) - lucky.begin();
    if (idx == lucky.size())
        return 0;
    ll last = L, cur = lucky[idx];
    while (idx < lucky.size() && lucky[idx] < R)
    {
        res += (lucky[idx] - last + 1) * lucky[idx];
        last = lucky[idx] + 1;
        idx++;
    }
    if (idx < lucky.size())
        res += (R - last + 1) * lucky[idx];
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dfs(4);
    dfs(7);
    sort(lucky.begin(), lucky.end());
    cout << solve() << "\n";
    return 0;
}