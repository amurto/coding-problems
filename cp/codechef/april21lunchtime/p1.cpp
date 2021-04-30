#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    int n;
    string str;
    cin >> n >> str;
    vector<int> cnt(2);
    for (int i = 0; i < n; i++)
    {
        cnt[str[i] - '0']++;
        if (cnt[0] <= cnt[1])
            return true;
    }
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