#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool pal(string &str, int n)
{
    for (int i = 0, j = n - 1; i < j; i++, j--)
        if (str[i] != str[j])
            return false;
    return true;
}

void solve()
{
    string str;
    cin >> str;
    int n = str.length();
    if (count(str.begin(), str.end(), 'a') == n)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    if (pal(str, n))
        cout << 'a' << str << "\n";
    else
    {
        for (int i = 0; i < n; i++)
        {
            if (i == n / 2)
                cout << 'a';
            cout << str[i];
        }
        cout << "\n";
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