#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

bool solve()
{
    string str;
    cin >> str;
    int n = str.length();
    vector<int> cnt(26);
    for (char ch : str)
        cnt[ch - 'a']++;
    multiset<int> ms;
    for (int c : cnt)
        if (c > 0)
            ms.insert(c);
    while (!ms.empty() && *ms.begin() == 1)
    {
        if (*ms.rbegin() == 1)
            return false;
        int last = *ms.rbegin();
        last -= 2;
        ms.erase(--ms.end());
        ms.erase(ms.begin());
        if (last > 0)
            ms.insert(last);
    }
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