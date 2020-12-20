#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n, close = 0, rem = 0;
    cin >> n;
    string str;
    cin >> str;
    int i = n - 1;
    while (i >= 0 && str[i] == ')')
    {
        i--;
        close++;
    }
    if (close > (n - close))
        return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "Yes\n" : cout << "No\n";
    return 0;
}