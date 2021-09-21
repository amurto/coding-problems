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
    string str = "";
    for (int i = 0; i < n; i++)
        str.pb('(');
    for (int i = 0; i < n; i++)
        str.pb(')');
    cout << str << "\n";
    for (int i = 0, cur = n; i < n - 1; i++, cur--)
    {
        swap(str[cur - 1], str[cur]);
        cout << str << "\n";
    }
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