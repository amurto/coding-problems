#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back

int solve()
{
    string str;
    cin >> str;
    vector<int> f(26);
    for (char ch : str)
        f[ch - 'a']++;
    for (int i = 0; i < 26; i++)
        f[i] = min(f[i], 2);
    vector<int> cnt(3);
    for (int i = 0; i < 26; i++)
        cnt[f[i]]++;
    return cnt[1] / 2 + cnt[2];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        cout << solve() << "\n";
    return 0;
}