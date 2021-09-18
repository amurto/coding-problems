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

const int inf = 1e6 + 5;
ll solve()
{
    int n;
    string str;
    cin >> n >> str;
    ll res = 0;
    vector<int> dis(n, inf);
    int pre = inf, suf = inf;
    for (int i = 0; i < n; i++)
    {
        pre++;
        if (str[i] == '1')
            pre = 0;
        dis[i] = min(dis[i], pre);
    }
    for (int i = n - 1; i >= 0; i--)
    {
        suf++;
        if (str[i] == '1')
            suf = 0;
        dis[i] = min(dis[i], suf);
        res += 1ll * dis[i];
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int tc = 1; tc <= t; tc++)
        cout << "Case #" << tc << ": " << solve() << "\n";
    return 0;
}