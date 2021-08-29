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

const int inf = 2e9 + 5;
int solve()
{
    int n, x = inf;
    cin >> n;
    vector<int> a(n), b(n - 1);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n - 1; i++)
        cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    if (n == 2)
    {
        for (int i = 0; i < n; i++)
            if (b[0] - a[i] > 0)
                x = min(x, b[0] - a[i]);
        return x;
    }
    int diff = b[0] - a[0];
    if (diff > 0)
    {
        int cur = 1;
        for (int i = 1; cur < n - 1 && i < n; i++)
            if (b[cur] - a[i] == diff)
                cur++;
        if (cur == n - 1)
            x = min(x, diff);
    }
    diff = b[0] - a[1];
    if (diff > 0)
    {
        int cur = 1;
        for (int i = 2; cur < n - 1 && i < n; i++)
            if (b[cur] - a[i] == diff)
                cur++;
        if (cur == n - 1)
            x = min(x, diff);
    }
    return x;
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