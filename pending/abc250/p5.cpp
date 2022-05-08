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

void solve()
{
    int n, q;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), preA(n + 1), preB(n + 1);
    map<int, int> posA, posB;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        posA[a[i]] = posB[a[i]] = n + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        posA[b[i]] = posB[b[i]] = n + 1;
    }
    for (int i = n; i > 0; i--)
    {
        posA[a[i]] = i;
        posB[b[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        preA[i] = max(preA[i - 1], posB[a[i]]);
        preB[i] = max(preB[i - 1], posA[b[i]]);
    }
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        (preA[x] <= y && preB[y] <= x) ? cout << "Yes\n" : cout << "No\n";
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
