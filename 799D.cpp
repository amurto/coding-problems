// https://codeforces.com/contest/799/problem/D
// Field expansion

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

const int inf = 1e9 + 7;
ll pw(ll x, int p)
{
    if (p == 0)
        return 1;
    return x * pw(x, p - 1);
}

int dfs(vector<pii> &seq, ll a, ll b, ll h, ll w, int cur)
{
    if (cur == seq.size())
        return inf;
        
}

int solve()
{
    ll a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.rbegin(), arr.rend());
    int id = 0;
    ll p = 1;
    while (id < n && p < 1e10)
    {
        p *= 1ll * arr[id];
        id++;
    }
    vector<pii> seq;
    for (int i = 0; i < id;)
    {
        int j = i;
        while (j < id && arr[i] == arr[j])
            j++;
        seq.pb({arr[i], j - i});
        i = j;
    }
    int mn = inf;
    for (int k = 0; k < 2; k++)
    {
        dfs(seq, h, w, a, b, 0);
        swap(a, b);
    }
    return (mn >= inf) ? -1 : mn;
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