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
    int n, m;
    cin >> n >> m;
    vector<string> arr1(n), arr2(m);
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    map<string, bool> vis;
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
        vis[arr2[i]] = true;
    }
    for (string s : arr1)
        if (vis[s])
            cout << "Yes\n";
        else
            cout << "No\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}