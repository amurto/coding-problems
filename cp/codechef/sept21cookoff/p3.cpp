#ifdef use_debug
#define TERMINAL
#include "headers/debug.cpp"
#else
#define d(...) 0
#endif
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back

bool dfs(vector<int> &seq, int g, int cur, int k, int sz)
{
    if (g == 1)
        return true;
    if (k == 0 || cur == sz)
        return false;
    return dfs(seq, g, cur + 1, k, sz) || dfs(seq, __gcd(g, seq[cur]), cur + 1, k - 1, sz);
}

bool solve()
{

    int n;
    cin >> n;
    int k = n / 2;
    if (n & 1)
        k++;
    vector<int> arr(n), seq;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 == 0)
            seq.pb(arr[i] / 2);
    }
    int sz = (int)seq.size();
    if (sz < k)
        return false;
    if (sz <= 22)
        return dfs(seq, 0, 0, k, sz);
    int g = 0;
    for (int i = 0; i < sz; i++)
        g = __gcd(g, seq[i]);
    return g == 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}