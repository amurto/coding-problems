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
    vector<int> last(26);
    for (int i = 0; i < n; i++)
        last[str[i] - 'a'] = i;
    int mx = 0;
    for (int i = 0; i < n; i++)
        if (last[str[i] - 'a'] > i)
            mx++;
        else
            break;
    return str.substr(mx, n - mx);
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