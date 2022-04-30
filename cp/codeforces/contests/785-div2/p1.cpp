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
    string str;
    cin >> str;
    int n = str.length(), score = 0;
    for (char ch : str)
        score += ch - 'a' + 1;
    if (n % 2 == 0)
        cout << "Alice " << score << "\n";
    else if (n == 1)
        cout << "Bob " << score << "\n";
    else
    {
        score = score - 2 * min(str[0] - 'a' + 1, str[n - 1] - 'a' + 1);
        cout << "Alice " << score << "\n";
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