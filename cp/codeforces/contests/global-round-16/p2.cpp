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

int solve()
{
    string str;
    cin >> str;
    int n = str.length(), cur = 0, z = 0;

    for (int i = 0; i < n;)
    {
        char ch = str[i];
        while (i < n && ch == str[i])
        {
            if (ch == '0')
                z++;
            i++;
        }
        if (ch == '0')
            cur++;
    }
    if (z == n)
        return 1;
    return min(cur, 2);
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