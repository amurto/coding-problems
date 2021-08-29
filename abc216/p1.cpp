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
    string str, ans = "";
    cin >> str;
    int n = str.length();
    for (int i = 0; i < n && str[i] != '.'; i++)
        ans.pb(str[i]);
    if (str[n - 1] <= '2')
        ans += "-";
    else if (str[n - 1] > '6' && str[n - 1] <= '9')
        ans += "+";
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << solve() << "\n";
    return 0;
}