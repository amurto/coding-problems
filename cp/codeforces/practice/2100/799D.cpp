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
        return 1ll;
    return x * pw(x, p - 1);
}

int dfs(vector<pii> &seq, ll p, ll m, ll a, ll b, ll h, ll w, int cur)
{
    if (h >= a)
        return (w * (p / m)) >= b;
    if (cur == seq.size())
        return 0;
    int ans = 0;
    for (int i = 0; i <= seq[cur].second; i++)
        ans |= dfs(seq, p, m * pw(1ll * seq[cur].first, i), a, b, h * pw(1ll * seq[cur].first, i), w, cur + 1);
    return ans;
}

vector<pii> compress(vector<int> &arr, int id, int n)
{
    vector<pii> seq;
    for (int i = 0; i < id;)
    {
        int j = i;
        while (j < id && arr[i] == arr[j])
            j++;
        seq.pb({arr[i], j - i});
        i = j;
    }
    return seq;
}

int solve()
{
    ll a, b, h, w, n;
    cin >> a >> b >> h >> w >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (max(h, w) >= max(a, b) && min(h, w) >= min(a, b))
        return 0;
    sort(arr.rbegin(), arr.rend());
    int id = 0;
    ll p = 1;
    while (id < n && p < 1e10)
    {
        p *= 1ll * arr[id];
        id++;
    }
    int low = 1, high = id, mn = inf;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        vector<pii> seq = compress(arr, mid, n);
        p = 1;
        for (int i = 0; i < mid; i++)
            p *= arr[i];
        if (dfs(seq, p, 1, a, b, h, w, 0) || dfs(seq, p, 1, a, b, w, h, 0))
        {
            mn = min(mn, mid);
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return (mn >= inf) ? -1 : mn;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}