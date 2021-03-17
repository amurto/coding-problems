#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

const int N = 1e7 + 5;

// O(n)
vector<int> lp(N + 1), pr;
void linear_sieve()
{
    for (int i = 2; i <= N; i++)
    {
        if (lp[i] == 0)
        {
            lp[i] = i;
            pr.push_back(i);
        }
        for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
            lp[i * pr[j]] = pr[j];
    }
}

int fac(int x)
{
    map<int, int> mp;
    while (x > 1)
    {
        mp[lp[x]]++;
        x /= lp[x];
    }
    int res = 1;
    for (auto m : mp)
        if (m.second & 1)
            res *= m.first;
    if (res == 1)
        return 0;
    return res;
}

int solve()
{
    int n, k, res = 0;
    cin >> n >> k;
    vector<int> arr(n), c(n), nxt(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        c[i] = fac(arr[i]);
        mp[c[i]].pb(i);
    }
    for (auto m : mp)
    {
        for (int i = 0; i < m.second.size() - 1; i++)
            nxt[m.second[i]] = m.second[i + 1];
        nxt[m.second[m.second.size() - 1]] = n;
    }
    int b = n;
    for (int i = 0; i < n; i++)
    {
        if (i == b)
        {
            res++;
            b = nxt[i];
        }
        else
            b = min(b, nxt[i]);
    }
    res++;
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    linear_sieve();
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}