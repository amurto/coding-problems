#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

string solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (n == 1)
        return arr[0];
    vector<string> rep(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> rep[i];
    string res = "";
    for (int j = 0; j < m; j++)
    {
        vector<int> cnt1(26), cnt2(26);
        for (int i = 0; i < n; i++)
            cnt1[arr[i][j] - 'a']++;
        for (int i = 0; i < n - 1; i++)
            cnt2[rep[i][j] - 'a']++;
        for (int i = 0; i < 26; i++)
            if (cnt1[i] != cnt2[i])
                res.pb(char(i + 'a'));
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << endl;
    return 0;
}