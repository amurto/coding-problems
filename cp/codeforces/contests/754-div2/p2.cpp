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
    string str;
    cin >> n >> str;
    string tmp = str;
    sort(tmp.begin(), tmp.end());
    if (str == tmp)
    {
        cout << "0\n";
        return;
    }
    vector<int> ops;
    for (int i = 0; i < n; i++)
        if (str[i] != tmp[i])
            ops.pb(i);
    cout << "1\n";
    cout << (int)ops.size() << " ";
    for (int x : ops)
        cout << x + 1 << " ";
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