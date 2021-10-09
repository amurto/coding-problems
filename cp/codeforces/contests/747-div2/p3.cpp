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

bool eq(string &str, char c)
{
    for (char ch : str)
        if (ch != c)
            return false;
    return true;
}
void solve()
{
    int n;
    char c;
    string str;
    cin >> n >> c >> str;
    if (eq(str, c))
    {
        cout << "0\n";
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        int cnt = 0;
        for (int j = i; j <= n; j += i)
            cnt += (str[j - 1] != c);
        if (cnt == 0)
        {
            cout << "1\n";
            cout << i << "\n";
            return;
        }
    }
    cout << "2\n";
    cout << n - 1 << " " << n << "\n";
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