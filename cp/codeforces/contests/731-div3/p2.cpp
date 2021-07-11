#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    string str;
    cin >> str;
    int n = str.length();
    vector<int> pos(26), cnt(26);
    for (int i = 0; i < n; i++)
    {
        cnt[str[i] - 'a']++;
        pos[str[i] - 'a'] = i;
    }
    if (cnt[0] != 1)
        return false;
    for (int i = 1; i < 26; i++)
        if (cnt[i] > 1 || (cnt[i] == 1 && cnt[i - 1] == 0))
            return false;
    for (int j = pos[0] + 1; j < n; j++)
        if (str[j] < str[j - 1])
            return false;
    for (int j = pos[0] - 1; j >= 0; j--)
        if (str[j] < str[j + 1])
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