#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n, k;
    string str;
    cin >> n >> k >> str;
    if (k * 2 == n)
        return false;
    for (int i = 0, j = n - 1; i < k; i++, j--)
        if (str[i] != str[j])
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}