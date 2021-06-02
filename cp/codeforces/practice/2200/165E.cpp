// https://codeforces.com/contest/165/problem/E
// Compatible Numbers

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int count_bits(int x)
{
    int cnt = 0;
    while (x > 0)
    {
        x >>= 1;
        cnt++;
    }
    return cnt;
}

void solve()
{
    int n, mx = 0;
    cin >> n;
    vector<int> arr(n + 1);
    arr[0] = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    int m = count_bits(mx);
    vector<int> f(1 << m);
    for (int i = 1; i <= n; i++)
        f[arr[i]] = i;
    for (int b = 0; b < m; b++)
        for (int mask = 0; mask < (1 << m); mask++)
            if ((mask >> b) & 1)
                f[mask] = max(f[mask], f[mask ^ (1 << b)]);
    for (int i = 1; i <= n; i++)
        cout << arr[f[((1 << m) - 1) ^ arr[i]]] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}