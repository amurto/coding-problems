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

const int N = 2e5 + 5;
vector<int> divs[N];
void init()
{
    for (int i = 1; i < N; i++)
        for (int j = i; j < N; j += i)
            divs[j].pb(i);
}
void solve()
{
    int n, g = 0;
    cin >> n;
    vector<int> arr(n), cnt(30);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        for (int b = 0; b < 30; b++)
            cnt[b] += ((arr[i] >> b) & 1);
    }
    for (int i = 0; i < 30; i++)
        g = __gcd(g, cnt[i]);
    vector<int> res;
    if (g == 0)
        for (int i = 1; i <= n; i++)
            res.pb(i);
    else
        res = divs[g];
    for (int x : res)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    init();
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}