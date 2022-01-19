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

string solve()
{
    string str;
    cin >> str;
    int n = (int)str.length();
    for (int i = n - 1; i > 0; i--)
    {
        int l = str[i - 1] - '0', r = str[i] - '0';
        if (l + r >= 10)
        {
            str[i - 1] = '0' + (l + r) / 10;
            str[i] = '0' + (l + r) % 10;
            return str;
        }
    }
    int l = str[0] - '0', r = str[1] - '0';
    str = str.substr(1, n - 1);
    str[0] = '0' + l + r;
    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}