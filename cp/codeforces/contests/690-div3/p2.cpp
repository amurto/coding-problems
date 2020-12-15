#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    if (str.substr(0, 4) == "2020" || str.substr(n - 4, 4) == "2020")
        return true;
    if (str.substr(0, 3) == "202" && str.substr(n - 1, 1) == "0")
        return true;
    if (str.substr(0, 1) == "2" && str.substr(n - 3, 3) == "020")
        return true;
    if (str.substr(0, 2) == "20" && str.substr(n - 2, 2) == "20")
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
        solve() ? cout << "YES\n" : cout << "NO\n";
    return 0;
}