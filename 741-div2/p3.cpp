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
    int h = n / 2;
    if (count(str.begin(), str.end(), '0') == 0)
    {
        cout << 1 << " " << h << " ";
        cout << n - h + 1 << " " << n << "\n";
        return;
    }
    for (int i = 0; i < n - h; i++)
    {
        if (str[i] == '0')
        {
            cout << i + 1 << " " << n << " ";
            cout << i + 2 << " " << n << "\n";
            return;
        }
    }
    for (int i = n - h; i < n; i++)
    {
        if (str[i] == '0')
        {
            cout << 1 << " " << i + 1 << " ";
            cout << 1 << " " << i << "\n";
            return;
        }
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