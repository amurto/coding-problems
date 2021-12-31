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
    int n;
    cin >> n;
    string str;
    vector<int> arr(n), res(n), cnt(2);
    vector<vector<int>> st(2);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> str;
    for (int i = 0; i < n; i++)
    {
        cnt[str[i] - '0']++;
        st[str[i] - '0'].pb(i);
    }
    for (int i = 0; i < 2; i++)
        sort(st[i].begin(), st[i].end(), [&](int &i1, int &i2)
             { return arr[i1] < arr[i2]; });
    for (int i = 1, j = 0; i <= cnt[0]; i++, j++)
        res[st[0][j]] = i;
    for (int i = cnt[0] + 1, j = 0; i <= n; i++, j++)
        res[st[1][j]] = i;
    for (int x : res)
        cout << x << " ";
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
    return 0;
}