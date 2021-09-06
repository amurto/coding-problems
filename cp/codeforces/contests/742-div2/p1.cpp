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
    string res = "";
    vector<vector<char>> arr(2, vector<char>(n, '0'));
    for (int i = 0; i < n; i++)
        cin >> arr[0][i];
    for (int i = 0; i < n; i++)
    {
        if (arr[0][i] == 'U')
            arr[1][i] = 'D';
        else if (arr[0][i] == 'D')
            arr[1][i] = 'U';
        else
            arr[1][i] = arr[0][i];
        res.pb(arr[1][i]);
    }
    cout << res << "\n";
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