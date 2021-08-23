// https://codeforces.com/contest/980/problem/D
// Perfect Groups

#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
const int N = 1e8 + 5;
bool vis[N][2];

int factorize(int x)
{
    if (x == 0)
        return 0;
    int v = 1;
    if (x < 0)
        v = -1;
    x = abs(x);
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0)
            {
                cnt ^= 1;
                x /= i;
            }
            if (cnt)
                v *= i;
        }
    }
    if (x > 1)
        v *= x;
    return v;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n), res(n + 1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        arr[i] = factorize(arr[i]);
        vis[abs(arr[i])][arr[i] >= 0] = false;
    }
    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (int j = i; j >= 0; j--)
        {
            if (!vis[abs(arr[j])][arr[j] >= 0])
            {
                vis[abs(arr[j])][arr[j] >= 0] = true;
                cur++;
            }
            res[max(1, cur - vis[0][1])]++;
        }
        for (int j = i; j >= 0; j--)
            vis[abs(arr[j])][arr[j] >= 0] = false;
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}