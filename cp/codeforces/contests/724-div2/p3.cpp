#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

void solve()
{
    map<char, int> mp;
    map<pair<int, int>, int> last;
    mp['D'] = 0;
    mp['K'] = 1;
    int n;
    string str;
    cin >> n >> str;
    vector<int> arr(n + 1), dp(n + 1), cnt(2);
    for (int i = 0; i < n; i++)
        arr[i + 1] = mp[str[i]];
    for (int i = 1; i <= n; i++)
    {
        cnt[arr[i]]++;
        int g = __gcd(cnt[0], cnt[1]);
        int l = cnt[0] / g, r = cnt[1] / g;
        dp[i] = dp[last[{l, r}]] + 1;
        last[{l, r}] = i;
    }
    for (int i = 1; i <= n; i++)
        cout << dp[i] << " ";
    cout << "\n";
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