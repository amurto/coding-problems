// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1266
// 10325 - The Lottery
// Inclusion - Exclusion Principle

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

ll lcm(ll a, ll b)
{
    return (a * b) / __gcd(a, b);
}

ll dfs(vector<ll> arr, ll N, ll M, int cur, int cnt)
{
    if (cur == arr.size())
    {
        if (cnt % 2 == 0)
            return N / M;
        return -N / M;
    }
    ll res = dfs(arr, N, M, cur + 1, cnt) + dfs(arr, N, lcm(M, arr[cur]), cur + 1, cnt + 1);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll n;
    int m;
    while (cin >> n >> m)
    {
        vector<ll> arr(m);
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        cout << dfs(arr, n, 1, 0, 0) << "\n";
    }
    return 0;
}