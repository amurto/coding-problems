// https://codeforces.com/contest/459/problem/C
// Pashmak and Buses

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool check(int n, int k, int d)
{
    ll cur = 1;
    for (int i = 0; cur <= n && i < d; i++)
        cur *= 1ll * k;
    return cur < n;
}

void solve()
{
    int n, k, d;
    cin >> n >> k >> d;
    vector<vector<int>> arr(d, vector<int>(n));
    if (check(n, k, d))
    {
        cout << "-1\n";
        return;
    }
    // base 10 to base k
    for (int i = 0; i < n; i++)
    {
        int cur = i;
        for (int j = 0; cur > 0 && j < d; j++)
        {
            arr[j][i] = cur % k;
            cur /= k;
        }
    }
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] + 1 << " ";
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}