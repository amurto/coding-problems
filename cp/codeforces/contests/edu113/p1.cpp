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
    for (int i = 1; i < n; i++)
    {
        if (str[i - 1] != str[i])
        {
            cout << i << " " << i + 1 << "\n";
            return;
        }
    }
    cout << "-1 -1\n";
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